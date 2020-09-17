//
// Created by vydra on 9/18/20.
//

#pragma once

#include "systems/IControl.h"
#include "systems/scenes_systems/game_loop_systems/world/IWorldSystem.hpp"

class GLCControlSelectEnd : public IControl {
 private:
  IWorldSystem* world_system;

 public:
  GLCControlSelectEnd(IWorldSystem* input_world_system) : IControl("GLCControlSelectEnd") {}

  void execute() override {}
};
