#include "g2o_frontend/basemath/bm_se2.h"
#include "alignment_line2d_linear.h"
#include <Eigen/SVD>
#include <Eigen/Cholesky>

#include <iostream>
using namespace std;

namespace g2o_frontend{
  using namespace g2o;
//   using namespace Slam2dAddons;
  using namespace Eigen;

	Vector3d line2d_remapCartesian(Eigen::Isometry2d& _X, Vector3d& _l){
		Vector3d tl;
		tl.setZero();
		
		Eigen::Matrix3d X = _X.matrix();
		tl.block<2,1>(0,0) = X.block<2,2>(0,0) * _l.block<2,1>(0,0);
		tl(3) += X.block<2,1>(0,2).transpose() * tl.block<2,1>(0,0);
		
		return tl;
	}
	
  AlignmentAlgorithmLine2DLinear::AlignmentAlgorithmLine2DLinear(): AlignmentAlgorithmSE2Line2D(2) {
  }
  bool AlignmentAlgorithmLine2DLinear::operator()(AlignmentAlgorithmLine2DLinear::TransformType& transform, const CorrespondenceVector& correspondences, const IndexVector& indices){
    if ((int)indices.size()<minimalSetSize())
      return false;
    transform = Isometry2d::Identity();
    Vector6d _x = homogeneous2vector_2d(transform.matrix());
		Eigen::Matrix3d Omega = Eigen::Matrix3d::Identity()*1000; 
		
		//	considering only the rotational part to first compute rotational part of the transformation
		Vector4d x;
		x.head<4>() = _x.head<4>();

    Matrix4d H;
    H.setZero();
    Vector4d b;
    b.setZero();
    Matrix2x4d A;
		
		//to compute the error
		double err = 0;
		
    for (size_t i=0; i<indices.size(); i++){
      A.setZero();
      const Correspondence& c = correspondences[indices[i]];
			const EdgeLine2D* edge = static_cast<const EdgeLine2D*>(c.edge());
      const VertexLine2D* v1 = static_cast<const VertexLine2D*>(edge->vertex(0));
      const VertexLine2D* v2 = static_cast<const VertexLine2D*>(edge->vertex(1));
//      const AlignmentAlgorithmLine2DLinear::PointEstimateType& li= v1->estimate();
//      const AlignmentAlgorithmLine2DLinear::PointEstimateType& lj= v2->estimate();
			Vector2d l1 = v1->estimate(); //theta, rho
			Vector2d l2 = v2->estimate();
			Vector3d li(cos(l1[0]), sin(l1[0]), l1[1]);
			Vector3d lj(cos(l2[0]), sin(l2[0]), l2[1]);
			
      A.block<1,2>(0,0)=lj.head<2>().transpose();
      A.block<1,2>(1,2)=lj.head<2>().transpose();

      Vector2d ek = -li.head<2>();
      ek += A*x;

      H+=A.transpose()*Omega.block<2,2>(0,0)*A;
      b+=A.transpose()*Omega.block<2,2>(0,0)*ek;
			err+= ek.transpose()*Omega.block<2,2>(0,0)*ek;
    }
    LDLT<Matrix4d> ldlt(H);
    if (ldlt.isNegative())
      return false;
    x=ldlt.solve(b); // using a LDLT factorizationldlt;
		
		cout << "partial (R) before rotation: " << err << endl;
		
		//saving the rotational part of the X
    _x.head<4>() = x.head<4>();
    Matrix3d _X = transform.matrix();
		_X.block<2,2>(0,0) += vector2homogeneous_2d(_x).block<2,2>(0,0);
		Vector2d t = _X.block<2,1>(0,2);
		
cout << "AAAAAAAAAAAAAAAAAA X old: \n" << transform.matrix() << endl;
cout << "AAAAAAAAAAAAAAAAAA X updated: \n" << _X << endl;
		
//     // recondition the rotation 
    JacobiSVD<Matrix2d> svd(_X.block<2,2>(0,0), Eigen::ComputeThinU | Eigen::ComputeThinV);
    if (svd.singularValues()(0)<.5)
      return false;
    Matrix2d R = svd.matrixU()*svd.matrixV().transpose();
    Isometry2d Xnew = Isometry2d::Identity();
    Xnew.linear() = R;
    Xnew.translation() = t;
cout << "R after reconditioning the rotation:\n" << R << endl;

    Matrix2d H2 = Matrix2d::Zero();
    Vector2d b2 = Vector2d::Zero();
		Vector2d A2 = Vector2d::Zero();
		//setting the rotational err to zero, recompute the translation
		err = 0;
    for (size_t i=0; i<indices.size(); i++){
			const Correspondence& c = correspondences[indices[i]];
			const EdgeLine2D* edge = static_cast<const EdgeLine2D*>(c.edge());
			const VertexLine2D* v1 = static_cast<const VertexLine2D*>(edge->vertex(0));
			const VertexLine2D* v2 = static_cast<const VertexLine2D*>(edge->vertex(1));
//       const AlignmentAlgorithmLine2DLinear::PointEstimateType& li= v1->estimate();
//       const AlignmentAlgorithmLine2DLinear::PointEstimateType& lj= v2->estimate();
			Vector2d l1 = v1->estimate(); //theta, rho
			Vector2d l2 = v2->estimate();			
			Vector3d li(cos(l1[0]), sin(l1[0]), l1[1]);
			Vector3d lj(cos(l2[0]), sin(l2[0]), l2[1]);
			
			A2 = Xnew.linear() * lj.head<2>();
			double ek3 = -li[3];
			ek3+= lj[3] + A2.transpose()*t;
			H2 += A2*Omega(2,2)*A2.transpose();
			b2 += A2*Omega(2,2)*ek3;
			err += ek3*Omega(2,2)*ek3;
    }
    Vector2d dt;
    dt = H2.ldlt().solve(b2);
    t+=dt;
		Xnew.translation() = t;
cout << "t after recompute the translation: " << t.transpose() << endl;
		cout << "partial (T) after rotation: " << err << endl;
		
    transform = Xnew;
    cerr << "transform: " << endl;
    cerr << transform.matrix()/*homogeneous2vector_2d(transform.matrix()).transpose()*/ << endl;
		
		//computing the total error with the transform found
		err = 0;
		for (size_t i=0; i<indices.size(); i++){
			const Correspondence& c = correspondences[indices[i]];
			const EdgeLine2D* edge = static_cast<const EdgeLine2D*>(c.edge());
			const VertexLine2D* v1 = static_cast<const VertexLine2D*>(edge->vertex(0));
			const VertexLine2D* v2 = static_cast<const VertexLine2D*>(edge->vertex(1));
//       const AlignmentAlgorithmLine2DLinear::PointEstimateType& li= v1->estimate();
//       const AlignmentAlgorithmLine2DLinear::PointEstimateType& lj= v2->estimate();
			Vector2d l1 = v1->estimate(); //theta, rho
			Vector2d l2 = v2->estimate();			
			Vector3d li(cos(l1[0]), sin(l1[0]), l1[1]);
			Vector3d lj(cos(l2[0]), sin(l2[0]), l2[1]);
			
			Vector3d tlj = line2d_remapCartesian(Xnew, lj);
			Vector3d ek = tlj - li;
			//ek(3) = 0.;
			err += ek.transpose() * Omega * ek;
		}
// 		cout << "after all: " << err << endl;
    return true;
  }


  RansacLine2DLinear::RansacLine2DLinear():  GeneralizedRansac<AlignmentAlgorithmLine2DLinear>(2){
  }

}
