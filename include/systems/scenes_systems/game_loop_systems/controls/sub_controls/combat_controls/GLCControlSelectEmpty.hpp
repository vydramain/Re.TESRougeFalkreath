//
// Created by vydra on 9/15/20.
//

#pragma once

#include "systems/IControl.h"
#include "systems/scenes_systems/game_loop_systems/world/IWorldSystem.hpp"

class GLCControlSelectEmpty : public IControl {
 public:
  GLCControlSelectEmpty() : IControl("GLCControlSelectEmpty") {}

  void execute() override {}
};
