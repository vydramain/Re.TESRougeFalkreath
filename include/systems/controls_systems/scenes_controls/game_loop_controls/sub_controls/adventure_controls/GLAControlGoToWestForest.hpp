//
// Created by vydra on 8/25/20.
//

#pragma once

#include "systems/controls_systems/IControl.h"

class GLAControlGoToWestForest : public IControl {
 public:
  explicit GLAControlGoToWestForest() : IControl("GLAControlGoToWestForest") {}

  void execute() {}
};