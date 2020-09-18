//GLCControls
// Created by vydra on 9/15/20.
//

#pragma once

#include "systems/IControl.h"
#include "systems/scenes_systems/game_loop_systems/world/IWorldSystem.hpp"
#include "systems/scenes_systems/game_loop_systems/controls/sub_controls/combat_controls/GLCControlMap.hpp"

class GLCControls {
 private:
  GLCControlMap *control_map = nullptr;

 public:
  explicit GLCControls(IWorldSystem *input_world_system, ParameterQueryDataSet* input_data) {
    control_map = new GLCControlMap(input_world_system, input_data);
  }

  ~GLCControls() {
    delete control_map;
  }

  IControl *update() {
    auto key = terminal_read();
    return control_map->get_control(key);
  }
};