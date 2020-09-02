//
// Created by vydra on 7/30/20.
//

#pragma once

#include "GLAControlMap.h"
#include "systems/scenes_systems/game_loop_systems/location_systems/LocationSystem.h"

class GLAControls {
 private:
  GLAControlMap *control_map = nullptr;

 public:
  explicit GLAControls(LocationSystem *input_location) {
    control_map = new GLAControlMap(input_location);
  }
  ~GLAControls() {
    delete control_map;
  }

  IControl *update() {
    auto key = terminal_read();
    return control_map->get_control(key);
  }
};
