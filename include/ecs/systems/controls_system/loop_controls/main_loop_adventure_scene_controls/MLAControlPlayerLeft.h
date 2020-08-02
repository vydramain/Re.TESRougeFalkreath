//
// Created by vydra on 7/30/20.
//

#ifndef INCLUDE_ECS_SYSTEMS_CONTROLS_SYSTEM_LOOP_CONTROLS_MAIN_LOOP_ADVENTURE_SCENE_CONTROLS_MLACONTROLPLAYERLEFT_H_
#define INCLUDE_ECS_SYSTEMS_CONTROLS_SYSTEM_LOOP_CONTROLS_MAIN_LOOP_ADVENTURE_SCENE_CONTROLS_MLACONTROLPLAYERLEFT_H_

#include "ecs/systems/controls_system/IControl.h"

class MLAControlPlayerLeft : public IControl {
 private:
  Location* location;

 public:
  explicit MLAControlPlayerLeft(Location* input_location)
      : IControl("MLAControlPlayerLeft"), location(input_location) {}

  void execute() override {
    location->get_current_creatures()->get_creature(0)->go_left();
  }
};

#endif  // INCLUDE_ECS_SYSTEMS_CONTROLS_SYSTEM_LOOP_CONTROLS_MAIN_LOOP_ADVENTURE_SCENE_CONTROLS_MLACONTROLPLAYERLEFT_H_
