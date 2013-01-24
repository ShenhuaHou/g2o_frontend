#ifndef DRAWABLE
#define DRAWABLE

#include <Eigen/Geometry>
#include <GL/gl.h>
#include "gl_parameter.h"

class PWNQGLViewer;

class Drawable {
 public:
  Drawable();
  Drawable(Eigen::Isometry3f transformation_);
  virtual void draw() {}
  void setTransformation(Eigen::Isometry3f transformation_) { _transformation = transformation_; }
  virtual bool setParameter(GLParameter *parameter_) = 0;
  void setViewer(PWNQGLViewer *viewer_) { _viewer = viewer_; }
  PWNQGLViewer* viewer() { return _viewer; }
  Eigen::Isometry3f transformation() { return _transformation; }
  virtual GLParameter* parameter() = 0;

 protected:
  // Isometry transformation to apply when draw method is called.
  Eigen::Isometry3f _transformation;
  // Drawing p0arameter.
  GLParameter *_parameter;
  // Pointer to the DMQGLViewer.
  PWNQGLViewer *_viewer;
  // Draw stuffs reduction.
};

#endif
