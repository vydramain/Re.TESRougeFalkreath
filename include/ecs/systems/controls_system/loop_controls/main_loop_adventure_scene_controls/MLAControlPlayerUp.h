//
// Created by vydra on 7/30/20.
//

#ifndef INCLUDE_ECS_SYSTEMS_CONTROLS_SYSTEM_LOOP_CONTROLS_MAIN_LOOP_ADVENTURE_SCENE_CONTROLS_MLACONTROLPLAYERUP_H_
#define INCLUDE_ECS_SYSTEMS_CONTROLS_SYSTEM_LOOP_CONTROLS_MAIN_LOOP_ADVENTURE_SCENE_CONTROLS_MLACONTROLPLAYERUP_H_

#include "ecs/entities/location_enities/Location.h"
#include "ecs/systems/controls_system/IControl.h"

class MLAControlPlayerUp : public IControl {
 private:
  const Location* location;

 public:
  explicit MLAControlPlayerUp(const Location* input_location)
      : IControl("MLAControlPlayerUp"), location(input_location) {}

  void execute() override {
    location->get_races()->get_player()->go_up();
  }
};

#endif  // INCLUDE_ECS_SYSTEMS_CONTROLS_SYSTEM_LOOP_CONTROLS_MAIN_LOOP_ADVENTURE_SCENE_CONTROLS_MLACONTROLPLAYERUP_H_
