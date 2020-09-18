//
// Created by vydra on 9/15/20.
//

#pragma once

#include "systems/IControl.h"
#include "systems/scenes_systems/game_loop_systems/world/IWorldSystem.hpp"

class GLCControlSelectExit : public IControl {
 private:
  IWorldSystem* world_system;

 public:
  GLCControlSelectExit(IWorldSystem* input_world_system) : IControl("GLCControlSelectExit") {}

  void execute() override {}
};
