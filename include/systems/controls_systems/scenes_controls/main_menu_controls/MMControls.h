//
// Created by vydra on 7/31/20.
//

#pragma once

#include "./BearLibTerminal.h"
#include "systems/controls_systems/IControl.h"
#include "systems/controls_systems/scenes_controls/main_menu_controls/MMControlMap.h"

class MMControls {
 private:
  MMControlMap *control_map;

 public:
  explicit MMControls(MenuData *input_menu_data) {
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
