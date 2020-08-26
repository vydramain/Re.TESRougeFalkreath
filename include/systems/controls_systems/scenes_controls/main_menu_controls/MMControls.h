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
  explicit MMControls(const unsigned input_count, unsigned *input_highlighted) {
    control_map = new MMControlMap(input_count, input_highlighted);
  }
  ~MMControls() {
    delete control_map;
  }

  IControl *update() {
    auto key = terminal_read();
    return control_map->get_control(key);
  }
};
