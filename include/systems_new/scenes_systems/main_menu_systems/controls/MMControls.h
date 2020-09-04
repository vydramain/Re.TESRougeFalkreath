//
// Created by vydra on 7/31/20.
//

#pragma once

#include "./BearLibTerminal.h"
#include "MMControlMap.h"
#include "systems_new/IControl.h"

class MMControls {
 private:
  MMControlMap *control_map;

 public:
  explicit MMControls(ParameterQueryData *input_menu_data) {
    control_map = new MMControlMap(input_menu_data);
  }
  ~MMControls() {
    delete control_map;
  }

  IControl *update() {
    auto key = terminal_read();
    return control_map->get_control(key);
  }
};
