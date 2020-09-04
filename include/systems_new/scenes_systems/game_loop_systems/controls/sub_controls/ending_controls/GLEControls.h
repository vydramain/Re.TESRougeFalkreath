//
// Created by vydra on 7/31/20.
//

#pragma once

#include "./BearLibTerminal.h"
#include "GLEControlMap.h"
#include "systems_new/IControl.h"

class GLEControls {
 private:
  GLEControlMap *control_map;

 public:
  explicit GLEControls(LocationSystem *input_location_system, ParameterQueryData *input_ending_data) {
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
