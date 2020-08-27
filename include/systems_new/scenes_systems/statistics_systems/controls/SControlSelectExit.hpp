//
// Created by vydra on 8/19/20.
//

#pragma once

#include "systems/controls_systems/IControl.h"

class SControlSelectExit : public IControl {
 public:
  explicit SControlSelectExit() : IControl("SControlSelectExit") {}
  ~SControlSelectExit() override = default;

  void execute() override {}
};
