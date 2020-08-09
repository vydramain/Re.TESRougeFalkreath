//
// Created by vydra on 7/30/20.
//

#pragma once

#include "core/systems/controls_system/game_loop_controls/sub_controls/adventure_controls/GLAControlMap.h"

class GLAControls {
 private:
  GLAControlMap *control_map;

 public:
  explicit GLAControls(LocationSystem *input_location) : control_map(new GLAControlMap(input_location)) {}
  ~GLAControls() = default;

  IControl *update() {
    auto key = terminal_read();
    return control_map->get_control(key);
  }
};
