//
// Created by vydra on 9/15/20.
//

#pragma once

#include "systems/IControl.h"
#include "systems/scenes_systems/game_loop_systems/world/IWorldSystem.hpp"

class GLCControlSelectRight : public IControl {
 private:
  IWorldSystem* world_system;

 public:
  GLCControlSelectRight(IWorldSystem* input_world_system) : IControl("GLCControlSelectRight") {}

  void execute() override {}
};
