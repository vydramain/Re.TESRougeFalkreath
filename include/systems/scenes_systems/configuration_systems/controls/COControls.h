//
// Created by vydra on 7/31/20.
//

#pragma once

#include "./BearLibTerminal.h"
#include "systems/IControl.h"
#include "systems/scenes_systems/configuration_systems/controls/COControlMap.h"

class COControls {
 private:
  COControlMap *control_map;

 public:
  explicit COControls(IRenderSystem *input_render_system, ParameterQueryData *input_settings_data,
                      GameConfigurationData *input_global_configuration_data) {
    control_map = new COControlMap(input_render_system, input_settings_data, input_global_configuration_data);
  }

  ~COControls() {
    delete control_map;
  }

  IControl *update() {
    auto key = terminal_read();
    return control_map->get_control(key);
  }
};
