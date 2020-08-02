//
// Created by vydra on 7/31/20.
//

#ifndef INCLUDE_ECS_SYSTEMS_CONTROLS_SYSTEM_MENU_CONTROLS_MMCONTROLSELECTUP_H_
#define INCLUDE_ECS_SYSTEMS_CONTROLS_SYSTEM_MENU_CONTROLS_MMCONTROLSELECTUP_H_

#include <ecs/systems/controls_system/IControl.h>

class MMControlSelectUp : public IControl {
 private:
  const unsigned count_choices;
  unsigned *highlighted;

 public:
  explicit MMControlSelectUp(const unsigned input_count, unsigned *input_highlighted)
      : IControl("MMControlSelectUp"), count_choices(input_count) {
    highlighted = input_highlighted;
  }

  void execute() override {
    if (*highlighted > 1) {
      *highlighted -= 1;
    }
  }
};

#endif  // INCLUDE_ECS_SYSTEMS_CONTROLS_SYSTEM_MENU_CONTROLS_MMCONTROLSELECTUP_H_
