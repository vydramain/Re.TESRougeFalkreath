//
// Created by vydra on 7/31/20.
//

#pragma once

#include "systems/controls_systems/IControl.h"

class IGLControl : public IControl {
 public:
  explicit IGLControl(const char* input_name = "IGLControl") : IControl(input_name) {}

  virtual IControl* get_last_control() = 0;
  void execute() override = 0;
};
