//
// Created by vydra on 7/30/20.
//

#pragma once

#include "systems/IControl.h"
#include "systems/scenes_systems/game_loop_systems/controls/sub_controls/adventure_controls/GLAControlMap.h"
#include "systems/scenes_systems/game_loop_systems/world/IWorldSystem.hpp"

class GLAControls {
 private:
  GLAControlMap *control_map = nullptr;

 public:
  explicit GLAControls(IWorldSystem *input_world_system) {
    control_map = new GLAControlMap(input_world_system);
  }
  ~GLAControls() {
    delete control_map;
  }

  IControl *update() {
    auto key = terminal_read();
    return control_map->get_control(key);
  }
};
