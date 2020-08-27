//
// Created by vydra on 7/31/20.
//

#pragma once

#include "./BearLibTerminal.h"
#include "systems/controls_systems/IControl.h"
#include "systems/controls_systems/scenes_controls/game_loop_controls/sub_controls/ending_controls/GLEControlMap.h"

class GLEControls {
 private:
  GLEControlMap *control_map;

 public:
  explicit GLEControls(LocationSystem *input_location_system, MenuData *input_ending_data) {
    control_map = new GLEControlMap(input_location_system, input_ending_data);
  }
  ~GLEControls() {
    delete control_map;
  }

  IControl *update() {
    auto key = terminal_read();
    return control_map->get_control(key);
  }
};
