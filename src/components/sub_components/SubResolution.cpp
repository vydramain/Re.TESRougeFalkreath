//
// Created by vydra on 9/10/20.
//

#include "components/sub_components/SubResolution.hpp"

SubResolution::SubResolution() : AbsResolution() {}

SubResolution::~SubResolution() = default;

void SubResolution::set_1920x1080() {
  current_resolution = R_1920x1080;
}

void SubResolution::set_1280x720() {
  current_resolution = R_1280x720;
}
AbsResolution::resolution SubResolution::get_current_resolution() const {
  return current_resolution;
}
