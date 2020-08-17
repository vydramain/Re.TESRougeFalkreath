//
// Created by vydra on 7/30/20.
//

#pragma once

#include "systems/controls_systems/IControl.h"

class GLAControlExit : public IControl {
 public:
  GLAControlExit() : IControl("GLAControlExit") {}

  void execute() override {}
};
