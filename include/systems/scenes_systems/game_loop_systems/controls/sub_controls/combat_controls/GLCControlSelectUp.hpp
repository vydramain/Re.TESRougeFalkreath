//
// Created by vydra on 9/15/20.
//

#pragma once

#include "systems/IControl.h"
#include "systems/scenes_systems/game_loop_systems/world/IWorldSystem.hpp"

class GLCControlSelectUp : public IControl {
 private:
  IWorldSystem* world_system;
  ParameterQueryData* data;

 public:
  GLCControlSelectUp(IWorldSystem* input_world_system, ParameterQueryData* input_data)
      : IControl("GLCControlSelectUp") {
    world_system = input_world_system;
    data = input_data;
  }

  void execute() override {
    if (data->get_highlighted() > 1) {
      data->set_highlighted(data->get_highlighted() - 1);
    }
  }
};
