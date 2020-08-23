//
// Created by vydra on 8/19/20.
//

#pragma once

#include "systems/controls_systems/IControl.h"

class SLControlEmpty : public IControl {
 public:
  explicit SLControlEmpty() : IControl("SLControlEmpty") {}
  ~SLControlEmpty() override {}

  void execute() override {}
};
