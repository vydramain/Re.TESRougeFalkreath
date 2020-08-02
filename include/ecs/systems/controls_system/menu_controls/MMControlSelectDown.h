//
// Created by vydra on 7/31/20.
//

#ifndef INCLUDE_ECS_SYSTEMS_CONTROLS_SYSTEM_MENU_CONTROLS_MMCONTROLSELECTDOWN_H_
#define INCLUDE_ECS_SYSTEMS_CONTROLS_SYSTEM_MENU_CONTROLS_MMCONTROLSELECTDOWN_H_

#include <ecs/systems/controls_system/IControl.h>

class MMControlSelectDown : public IControl {
 private:
  const unsigned count_choices;
  unsigned *highlighted;

 public:
  explicit MMControlSelectDown(const unsigned input_count, unsigned *input_highlighted)
      : IControl("MMControlSelectDown"), count_choices(input_count) {
    highlighted = input_highlighted;
  }

  void execute() override {
    if (*highlighted < count_choices) {
      *highlighted += 1;
    }
  }
};

#endif  // INCLUDE_ECS_SYSTEMS_CONTROLS_SYSTEM_MENU_CONTROLS_MMCONTROLSELECTDOWN_H_
