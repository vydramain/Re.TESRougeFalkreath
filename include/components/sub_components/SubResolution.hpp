//
// Created by vydra on 9/10/20.
//

#pragma once

#include "components/abs_components/AbsResolution.hpp"

class SubResolution : public AbsResolution {
 public:
  explicit SubResolution();
  virtual ~SubResolution();

  void set_1920x1080();
  void set_1280x720();

  resolution get_current_resolution() const;
};