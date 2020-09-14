//
// Created by vydra on 9/15/20.
//

#pragma once

#include "systems/IControl.h"
#include "systems/scenes_systems/game_loop_systems/world/IWorldSystem.hpp"

class GLCControlSelectDown : public IControl {
 private:
  IWorldSystem* world_system;

 public:
  GLCControlSelectDown(IWorldSystem* input_world_system) : IControl("GLCControlSelectDown") {
    world_system = input_world_system;
  }

  void execute() override {}
};
