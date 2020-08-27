//
// Created by vydra on 8/19/20.
//

#pragma once

#include "systems/controls_systems/IControl.h"

class SControlEmpty : public IControl {
 public:
  explicit SControlEmpty() : IControl("SControlEmpty") {}
  ~SControlEmpty() override {}

  void execute() override {}
};
