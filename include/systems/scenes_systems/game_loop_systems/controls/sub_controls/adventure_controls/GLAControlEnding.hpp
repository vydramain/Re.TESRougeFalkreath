//
// Created by vydra on 8/18/20.
//

#pragma once

#include "systems/IControl.h"

class GLAControlEnding : public IControl {
 public:
  GLAControlEnding() : IControl("GLAControlEnding") {}

  void execute() override {}
};
