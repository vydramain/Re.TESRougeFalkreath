//
// Created by vydra on 7/31/20.
//

#pragma once

#include "./BearLibTerminal.h"
#include "systems/IControl.h"
#include "systems/scenes_systems/configuration_systems/controls/sub_controls/game_play_configuration_controls/GPCOControlMap.h"

class GPCOControls {
 private:
  GPCOControlMap *control_map;

 public:
  explicit GPCOControls(ParameterQueryData *input_settings_data,
                        GameConfigurationData *input_global_configuration_data) {
    control_map = new GPCOControlMap(input_settings_data, input_global_configuration_data);
  }

  ~GPCOControls() {
    delete control_map;
  }

  IControl *update() {
    auto key = terminal_read();
    return control_map->get_control(key);
  }
};
