//
// Created by vydra on 7/31/20.
//

#ifndef INCLUDE_ECS_SYSTEMS_CONTROLS_SYSTEM_MENU_CONTROLS_MMCONTROLSELECTENTER_H_
#define INCLUDE_ECS_SYSTEMS_CONTROLS_SYSTEM_MENU_CONTROLS_MMCONTROLSELECTENTER_H_

#include "core/systems/controls_system/IControl.h"

class MMControlSelectEnter : public IControl {
 public:
  explicit MMControlSelectEnter() : IControl("MMControlSelectEnter") {}
  ~MMControlSelectEnter() override = default;

  void execute() override {}
};

#endif  // INCLUDE_ECS_SYSTEMS_CONTROLS_SYSTEM_MENU_CONTROLS_MMCONTROLSELECTENTER_H_
