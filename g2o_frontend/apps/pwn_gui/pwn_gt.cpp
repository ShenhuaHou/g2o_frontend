#include "g2o_frontend/pwn_core/pointintegralimage.h"
#include "g2o_frontend/pwn_core/informationmatrixfinder.h"
#include "g2o_frontend/pwn_core/correspondencefinder.h"
#include "g2o_frontend/pwn_core/pinholepointprojector.h"
#include "g2o_frontend/pwn_core/statsfinder.h"
#include "g2o_frontend/pwn_core/aligner.h"

#include <qapplication.h>
#include "g2o_frontend/pwn_viewer/pwn_qglviewer.h"
#include "g2o_frontend/pwn_viewer/pwn_imageview.h"
#include "g2o_frontend/pwn_viewer/drawable_points.h"
#include "g2o_frontend/pwn_viewer/drawable_normals.h"
#include "g2o_frontend/pwn_viewer/drawable_covariances.h"
#include "g2o_frontend/pwn_viewer/drawable_correspondences.h"
#include "g2o_frontend/pwn_viewer/gl_parameter.h"
#include "g2o_frontend/pwn_viewer/gl_parameter_points.h"
#include "g2o_frontend/pwn_viewer/gl_parameter_normals.h"
#include "g2o_frontend/pwn_viewer/gl_parameter_covariances.h"
#include "g2o_frontend/pwn_viewer/gl_parameter_correspondences.h"
#include "pwn_gui_main_window.h"

#include "g2o/stuff/command_args.h"
#include "g2o/stuff/timeutil.h"

#include <iostream>
#include <fstream>

#include "g2o_frontend/basemath/bm_se3.h"
#include "g2o_frontend/pwn_cuda/cualigner.h"

#include <unistd.h>
							     
using namespace std;
using namespace pwn;

int main(int argc, char** argv) {
  /************************************************************************
   *                           Input Handling                             *
   ************************************************************************/
  
  // Depth image file (path+filename).
  string currentFilename, referenceFilename;

  // Variables for the input parameters. Just type on the command line
  // ./pwn_normal_extraction -h to have more details about them.
  float ng_scale = 1.0f;
  float ng_curvatureThreshold = 1.0f;
  int al_innerIterations = 1;
  int al_outerIterations = 10;
  int vz_step = 1;

  // Define the camera matrix, place here the values for the particular 
  // depth camera used (Kinect, Xtion or any other type). This particular
  // matrix is the one related to the Kinect.
  Matrix3f cameraMatrix;
  cameraMatrix <<     
    525.0f, 0.0f, 319.5f,
    0.0f, 525.0f, 239.5f,
    0.0f, 0.0f, 1.0f;

  cameraMatrix << 
    570.342f, 0.0f, 319.5f,
    0.0f, 570.342f, 239.5f,
    0.0f, 0.0f, 1.0f;

  // Input parameters handling.
  g2o::CommandArgs arg;
  
  // Optional input parameters.
  arg.param("ng_scale", ng_scale, 1.0f, "Specify the scaling factor to apply on the depth image. [float]");
  arg.param("ng_curvatureThreshold", ng_curvatureThreshold, 1.0f, "Specify the max surface curvature threshold for which normals are discarded. [float]");
  arg.param("al_innerIterations", al_innerIterations, 1, "Specify the inner iterations. [int]");
  arg.param("al_outerIterations", al_outerIterations, 10, "Specify the outer iterations. [int]");
  arg.param("vz_step", vz_step, 1, "A graphic element is drawn each vz_step elements. [int]");

  // Last parameter has to be the depth image file.
  arg.paramLeftOver("depthImageFile1", referenceFilename, "./test1.pgm", "First depth image file (.pgm image) to analyze. [string]", true);
  arg.paramLeftOver("depthImageFile2", currentFilename, "./test2.pgm", "Secodn depth image file (.pgm image) to analyze. [string]", true);

  // Set parser input.
  arg.parseArgs(argc, argv);
  
  /************************************************************************
   *                         Reading Depth Image                          *
   ************************************************************************/ 
  // The DepthImage object is used read a depth image from a .pgm image file. It is an extended Eigen 
  // matrix of unsigned char. 
  DepthImage referenceDepthImage, currentDepthImage;
  // Try to read the depth images given in input.
  if(!referenceDepthImage.load(referenceFilename.c_str(), true)) {
    cout << "Failure while loading the depth image: " << referenceFilename<< ", quitting program!" << endl;
    exit(-1);
  }
  if(!currentDepthImage.load(currentFilename.c_str(), true)) {
    cout << "Failure while loading the depth image: " << currentFilename << ", quitting program!" << endl;
    exit(-1);
  }
  cout << endl << "Loaded first depth image of size: " << referenceDepthImage.rows() << "x" << referenceDepthImage.cols() << endl;
  cout << endl << "Loaded second depth image of size: " << currentDepthImage.rows() << "x" << currentDepthImage.cols() << endl;
  
  /************************************************************************
   *                         Point Unprojection                           *
   ************************************************************************/
  cout << "Unprojecting points...";

  // Update the size of the index image.
  Eigen::MatrixXi referenceIndexImage, currentIndexImage;
  referenceIndexImage.resize(referenceDepthImage.rows(), referenceDepthImage.cols());
  currentIndexImage.resize(currentDepthImage.rows(), currentDepthImage.cols());
    
  // Set the camera matrix of the projector object.
  PinholePointProjector projector;
  projector.setCameraMatrix(cameraMatrix);
  
  // Get the points in the 3d euclidean space.
  Frame referenceFrame, currentFrame;
  projector.unProject(referenceFrame.points(), referenceIndexImage, referenceDepthImage);
  projector.unProject(currentFrame.points(), currentIndexImage, currentDepthImage);
  
  cout << " done." << endl;

  /************************************************************************
   *                         Normal Computation                           *
   ************************************************************************/
  cout << "Computing normals...";

  PointIntegralImage referenceIntegralImage, currentIntegralImage;
  MatrixXi referenceIntervalImage, currentIntervalImage;
  
  // Compute the integral images.
  referenceIntegralImage.compute(referenceIndexImage, referenceFrame.points());
  currentIntegralImage.compute(currentIndexImage, currentFrame.points());
    
  // Compute the intervals.
  projector.projectIntervals(referenceIntervalImage, referenceDepthImage, 0.1f);
  projector.projectIntervals(currentIntervalImage, currentDepthImage, 0.1f);
    
  // Resize the vector containing the stats to have the same length of the vector of points.
  referenceFrame.stats().resize(referenceFrame.points().size());
  currentFrame.stats().resize(currentFrame.points().size());
  PointStats zeroStats;
  zeroStats.setZero();
  std::fill(referenceFrame.stats().begin(), referenceFrame.stats().end(), zeroStats);
  std::fill(currentFrame.stats().begin(), currentFrame.stats().end(), zeroStats);
    
  // Creating the stas generator object. 
  StatsFinder statsGenerator;
  
  // Stats and normals computation.
  statsGenerator.compute(referenceFrame.normals(),
			 referenceFrame.stats(),
			 referenceFrame.points(),
			 referenceIntegralImage,
			 referenceIntervalImage,
			 referenceIndexImage,
			 ng_curvatureThreshold);
  statsGenerator.compute(currentFrame.normals(),
			 currentFrame.stats(),
			 currentFrame.points(),
			 currentIntegralImage,
			 currentIntervalImage,
			 currentIndexImage,
			 ng_curvatureThreshold);
    
  cout << " done." << endl;
  
  /************************************************************************
   *                         Omega Computation                            *
   ************************************************************************/
  cout << "Computing omegas...";

  // Creating the omegas generators objects.
  PointInformationMatrixFinder pointOmegaGenerator;
  NormalInformationMatrixFinder normalOmegaGenerator;
  
  // Omegas computation.
  pointOmegaGenerator.compute(referenceFrame.pointInformationMatrix(), referenceFrame.stats(), referenceFrame.normals());
  pointOmegaGenerator.compute(currentFrame.pointInformationMatrix(), currentFrame.stats(), currentFrame.normals());
  normalOmegaGenerator.compute(referenceFrame.normalInformationMatrix(), referenceFrame.stats(), referenceFrame.normals());
  normalOmegaGenerator.compute(currentFrame.normalInformationMatrix(), currentFrame.stats(), currentFrame.normals());

  cout << " done." << endl;

  /************************************************************************
   *                         Alignment Computation                        *
   ************************************************************************/
  CuAligner aligner;
  CorrespondenceFinder correspondenceFinder;
  Linearizer linearizer;
  //Aligner aligner;
  aligner.setProjector(&projector);
  aligner.setLinearizer(&linearizer);
  linearizer.setAligner(&aligner);
  aligner.setCorrespondenceFinder(&correspondenceFinder);
 
 aligner.setOuterIterations(al_outerIterations);
  aligner.setInnerIterations(al_innerIterations);

  cerr << "constructingObjects " << endl;
  
  aligner.setReferenceFrame(&referenceFrame);
  aligner.setCurrentFrame(&currentFrame);
  
  Isometry3f initialGuess = Isometry3f::Identity();
  Isometry3f sensorOffset = Isometry3f::Identity();
  aligner.setInitialGuess(initialGuess);
  aligner.setSensorOffset(sensorOffset);
  
  cout << "doing something: " << endl;
  aligner.align();
  	
  cout << "Final transformation: " << endl << aligner.T().matrix() << endl;
  
  /************************************************************************
   *                         Visualization                                *
   ************************************************************************/
  QApplication qApplication(argc, argv);
  PWNGuiMainWindow pwnGMW;
  pwnGMW.show();

  // Uncomment what you want to see in the viewer. 
  GLParameterPoints *pPointsRef,*pPointsCur;
  // GLParameterNormals *pNormalsRef, *pNormalsCur;
  // GLParameterCovariances *pCovariancesRef, *pCovariancesCur;
  // GLParameterCorrespondences *pCorrespondences;

  DrawablePoints *dPointsRef,*dPointsCur;
  // DrawableNormals *dNormalsRef, *dNormalsCur;
  // DrawableCovariances *dCovariancesRef, *dCovariancesCur;
  // DrawableCorrespondences *dCorrespondences;
  
  pPointsRef = new GLParameterPoints(1.0f, Vector4f(1.0f, 0.0f, 0.0f, 1.0f));
  pPointsRef->setStep(vz_step);
  pPointsCur = new GLParameterPoints(1.0f, Vector4f(0.0f, 0.0f, 1.0f, 1.0f));
  pPointsCur->setStep(vz_step);
  // pNormalsRef = new GLParameterNormals(1.0f, Vector4f(1.0f, 0.0f, 1.0f, 1.0f), 0.03f);
  // pNormalsRef->setStep(vz_step);
  // pNormalsCur = new GLParameterNormals(1.0f, Vector4f(1.0f, 0.0f, 1.0f, 1.0f), 0.03f);
  // pNormalsCur->setStep(vz_step);
  // pCovariancesRef = new GLParameterCovariances(1.0f, 
  // 					    Vector4f(0.0f, 1.0f, 0.0f, 1.0f), Vector4f(1.0f, 0.0f, 0.0f, 1.0f),
  // 					    0.02f, 0.03f);
  // pCovariancesRef->setStep(vz_step);
  // pCovariancesCur = new GLParameterCovariances(1.0f, 
  // 					    Vector4f(0.0f, 1.0f, 0.0f, 1.0f), Vector4f(1.0f, 0.0f, 0.0f, 1.0f),
  // 					    0.02f, 0.03f);
  // pCovariancesCur->setStep(vz_step);
  // pCorrespondences = new GLParameterCorrespondences(1.0f, Vector4f(1.0f, 0.0f, 1.0f, 1.0f), 1.0f);
  // pCorrespondences->setStep(vz_step);
  
  dPointsRef = new DrawablePoints(Isometry3f::Identity(), (GLParameter*)pPointsRef, &referenceFrame.points(), &referenceFrame.normals());
  dPointsCur = new DrawablePoints(aligner.T(), (GLParameter*)pPointsCur, &currentFrame.points(), &currentFrame.normals());
  // dNormalsRef = new DrawableNormals(Isometry3f::Identity(), (GLParameter*)pNormalsRef, referenceFrame.points(), referenceFrame.normals());
  // dNormalsCur = new DrawableNormals(aligner.T(), (GLParameter*)pNormalsCur, currentFrame.points(), currentFrame.normals());
  // dCovariancesRef = new DrawableCovariances(Isometry3f::Identity(), (GLParameter*)pCovariancesRef, referenceFrame.stats());
  // dCovariancesCur = new DrawableCovariances(aligner.T(), (GLParameter*)pCovariancesCur, currentFrame.stats());
  // dCorrespondences = new DrawableCorrespondences(aligner.T(), (GLParameter*)pCorrespondences, aligner.correspondenceFinder().numCorrespondences(),
  // 						 referenceFrame.points(), currentFrame.points(), aligner.correspondenceFinder().correspondences());  

  pwnGMW.viewer_3d->addDrawable((Drawable*)dPointsRef);
  pwnGMW.viewer_3d->addDrawable((Drawable*)dPointsCur);
  // pwnGMW.viewer_3d->addDrawable((Drawable*)dNormalsRef);
  // pwnGMW.viewer_3d->addDrawable((Drawable*)dNormalsCur);
  // pwnGMW.viewer_3d->addDrawable((Drawable*)dCovariancesRef);
  // pwnGMW.viewer_3d->addDrawable((Drawable*)dCovariancesCur);
  // pwnGMW.viewer_3d->addDrawable((Drawable*)dCorrespondences);
  
  while(!(*pwnGMW.closing())) {
    qApplication.processEvents();
  
    pwnGMW.viewer_3d->updateGL();

    usleep(10000);
  }
}
