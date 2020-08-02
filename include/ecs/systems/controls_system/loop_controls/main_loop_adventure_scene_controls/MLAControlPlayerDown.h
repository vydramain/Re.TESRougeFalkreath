//
// Created by vydra on 7/30/20.
//

#ifndef INCLUDE_ECS_SYSTEMS_CONTROLS_SYSTEM_LOOP_CONTROLS_MAIN_LOOP_ADVENTURE_SCENE_CONTROLS_MLACONTROLPLAYERDOWN_H_
#define INCLUDE_ECS_SYSTEMS_CONTROLS_SYSTEM_LOOP_CONTROLS_MAIN_LOOP_ADVENTURE_SCENE_CONTROLS_MLACONTROLPLAYERDOWN_H_

#include "ecs/systems/controls_system/IControl.h"

class MLAControlPlayerDown : public IControl {
 private:
  Location* location;

 public:
  explicit MLAControlPlayerDown(Location* input_location)
      : IControl("MLAControlPlayerDown"), location(input_location) {}

  void execute() override {
    location->get_current_creatures()->get_creature(0)->go_down(location->get_size_y());
  }
};

#endif  // INCLUDE_ECS_SYSTEMS_CONTROLS_SYSTEM_LOOP_CONTROLS_MAIN_LOOP_ADVENTURE_SCENE_CONTROLS_MLACONTROLPLAYERDOWN_H_
