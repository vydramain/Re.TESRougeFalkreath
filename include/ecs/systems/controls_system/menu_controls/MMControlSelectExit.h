//
// Created by vydra on 7/31/20.
//

#ifndef INCLUDE_ECS_SYSTEMS_CONTROLS_SYSTEM_MENU_CONTROLS_MMCONTROLSELECTEXIT_H_
#define INCLUDE_ECS_SYSTEMS_CONTROLS_SYSTEM_MENU_CONTROLS_MMCONTROLSELECTEXIT_H_

#include <ecs/systems/controls_system/IControl.h>

class MMControlSelectExit : public IControl {
 public:
  explicit MMControlSelectExit() : IControl("MMControlSelectExit") {}
  ~MMControlSelectExit() override = default;

  void execute() override {}
};

#endif  // INCLUDE_ECS_SYSTEMS_CONTROLS_SYSTEM_MENU_CONTROLS_MMCONTROLSELECTEXIT_H_
