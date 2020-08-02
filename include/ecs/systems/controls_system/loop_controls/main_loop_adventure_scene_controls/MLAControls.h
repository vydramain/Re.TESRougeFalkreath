//
// Created by vydra on 7/30/20.
//

#ifndef INCLUDE_ECS_SYSTEMS_CONTROLS_SYSTEM_LOOP_CONTROLS_MAIN_LOOP_ADVENTURE_SCENE_CONTROLS_MLACONTROLS_H_
#define INCLUDE_ECS_SYSTEMS_CONTROLS_SYSTEM_LOOP_CONTROLS_MAIN_LOOP_ADVENTURE_SCENE_CONTROLS_MLACONTROLS_H_

#include <BearLibTerminal.h>

#include "./MLAControlMap.h"

class MLAControls {
 private:
  MLAControlMap *control_map;

 public:
  explicit MLAControls(Location *input_location) : control_map(new MLAControlMap(input_location)) {}
  ~MLAControls() = default;

  IControl *update() {
    auto key = terminal_read();
    return control_map->get_control(key);
  }
};

#endif  // INCLUDE_ECS_SYSTEMS_CONTROLS_SYSTEM_LOOP_CONTROLS_MAIN_LOOP_ADVENTURE_SCENE_CONTROLS_MLACONTROLS_H_
