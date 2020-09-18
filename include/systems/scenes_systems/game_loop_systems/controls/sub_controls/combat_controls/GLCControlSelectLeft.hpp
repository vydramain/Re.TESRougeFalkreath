//
// Created by vydra on 9/15/20.
//

#pragma once

#include "systems/IControl.h"
#include "systems/scenes_systems/game_loop_systems/world/IWorldSystem.hpp"

class GLCControlSelectLeft : public IControl {
 private:
  IWorldSystem* world_system;

 public:
  GLCControlSelectLeft(IWorldSystem* input_world_system) : IControl("GLCControlSelectLeft") {}

  void execute() override {}
};
