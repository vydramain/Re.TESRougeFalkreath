//
// Created by vydra on 8/19/20.
//

#pragma once

#include "systems/controls_systems/IControl.h"

class SLControlSelectExit : public IControl {
 public:
  explicit SLControlSelectExit() : IControl("SLControlSelectExit") {}
  ~SLControlSelectExit() override = default;

  void execute() override {}
};
