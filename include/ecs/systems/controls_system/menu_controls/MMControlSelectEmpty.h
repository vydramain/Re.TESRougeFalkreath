//
// Created by vydra on 7/31/20.
//

#ifndef INCLUDE_ECS_SYSTEMS_CONTROLS_SYSTEM_MENU_CONTROLS_MMCONTROLSELECTEMPTY_H_
#define INCLUDE_ECS_SYSTEMS_CONTROLS_SYSTEM_MENU_CONTROLS_MMCONTROLSELECTEMPTY_H_

#include <ecs/systems/controls_system/IControl.h>

class MMControlSelectEmpty : public IControl {
 public:
  explicit MMControlSelectEmpty() : IControl("MMControlSelectEmpty") {}

  void execute() override {}
};

#endif  // INCLUDE_ECS_SYSTEMS_CONTROLS_SYSTEM_MENU_CONTROLS_MMCONTROLSELECTEMPTY_H_
