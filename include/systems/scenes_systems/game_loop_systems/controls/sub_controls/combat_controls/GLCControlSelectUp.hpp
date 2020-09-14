//
// Created by vydra on 9/15/20.
//

#pragma once

#include "systems/IControl.h"
#include "systems/scenes_systems/game_loop_systems/world/IWorldSystem.hpp"

class GLCControlSelectUp : public IControl {
 private:
  IWorldSystem* world_system;

 public:
  GLCControlSelectUp(IWorldSystem* input_world_system) : IControl("GLCControlSelectUp") {}

  void execute() override {}
};
