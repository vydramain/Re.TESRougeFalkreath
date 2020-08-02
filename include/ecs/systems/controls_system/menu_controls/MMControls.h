//
// Created by vydra on 7/31/20.
//

#ifndef INCLUDE_ECS_SYSTEMS_CONTROLS_SYSTEM_MENU_CONTROLS_MMCONTROLS_H_
#define INCLUDE_ECS_SYSTEMS_CONTROLS_SYSTEM_MENU_CONTROLS_MMCONTROLS_H_

#include <ecs/systems/controls_system/IControl.h>

#include "./MMControlMap.h"

class MMControls {
 private:
  MMControlMap *control_map;

 public:
  explicit MMControls(const unsigned input_count, unsigned *input_highlighted)
      : control_map(new MMControlMap(input_count, input_highlighted)) {}
  ~MMControls() = default;

  IControl *update() {
    auto key = terminal_read();
    return control_map->get_control(key);
  }
};

#endif  // INCLUDE_ECS_SYSTEMS_CONTROLS_SYSTEM_MENU_CONTROLS_MMCONTROLS_H_
