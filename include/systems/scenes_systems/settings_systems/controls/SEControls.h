//
// Created by vydra on 7/31/20.
//

#pragma once

#include "./BearLibTerminal.h"
#include "systems/IControl.h"
#include "systems/scenes_systems/settings_systems/controls/SEControlMap.h"

class SEControls {
 private:
  SEControlMap *control_map;

 public:
  explicit SEControls(ParameterQueryData *input_settings_data) {
    control_map = new SEControlMap(input_settings_data);
  }

  ~SEControls() {
    delete control_map;
  }

  IControl *update() {
    auto key = terminal_read();
    return control_map->get_control(key);
  }
};
