//
// Created by vydra on 9/15/20.
//

#pragma once

#include "systems/IControl.h"
#include "systems/scenes_systems/game_loop_systems/world/IWorldSystem.hpp"

class GLCControlSelectEnter : public IControl {
 private:
  IWorldSystem* world_system;

 public:
  GLCControlSelectEnter(IWorldSystem* input_world_system) : IControl("GLCControlSelectEnter") {}

  void execute() override {}
};
