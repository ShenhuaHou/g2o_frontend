#include "drawable.h"

Drawable::Drawable() {
  _transformation = Eigen::Isometry3f::Identity();
  //_parameter = 0;
  _viewer = 0;
}

Drawable::Drawable(Eigen::Isometry3f transformation_) {
  _transformation = transformation_;
  _viewer = 0;
}
