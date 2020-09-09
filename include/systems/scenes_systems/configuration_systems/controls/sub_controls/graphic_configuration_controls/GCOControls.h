//
// Created by vydra on 7/31/20.
//

#pragma once

#include "./BearLibTerminal.h"
#include "systems/IControl.h"
#include "systems/scenes_systems/configuration_systems/controls/sub_controls/graphic_configuration_controls/GCOControlMap.h"

class GCOControls {
 private:
  GCOControlMap *control_map;

 public:
  explicit GCOControls(ParameterQueryData *input_settings_data,
                       GameConfigurationData *input_global_configuration_data) {
    control_map = new GCOControlMap(input_settings_data, input_global_configuration_data);
  }

  ~GCOControls() {
    delete control_map;
  }

  IControl *update() {
    auto key = terminal_read();
    return control_map->get_control(key);
  }
};
