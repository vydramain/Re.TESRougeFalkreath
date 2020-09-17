//
// Created by vydra on 7/31/20.
//

#pragma once

#include "./BearLibTerminal.h"
#include "systems/scenes_systems/game_loop_systems/controls/sub_controls/ending_controls/GLEControlMap.h"
#include "systems/IControl.h"

class GLEControls {
 private:
  GLEControlMap *control_map;

 public:
  explicit GLEControls(IWorldSystem *input_location_system, ParameterQueryDataSet *input_ending_data) {
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
