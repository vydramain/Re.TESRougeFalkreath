//
// Created by vydra on 7/30/20.
//

#ifndef INCLUDE_ECS_SYSTEMS_CONTROLS_SYSTEM_LOOP_CONTROLS_MAIN_LOOP_ADVENTURE_SCENE_CONTROLS_MLACONTROLPLAYERRIGHT_H_
#define INCLUDE_ECS_SYSTEMS_CONTROLS_SYSTEM_LOOP_CONTROLS_MAIN_LOOP_ADVENTURE_SCENE_CONTROLS_MLACONTROLPLAYERRIGHT_H_

#include "ecs/entities/location_enity/Location.h"
#include "ecs/systems/controls_system/IControl.h"

class MLAControlPlayerRight : public IControl {
 private:
  const Location* location;

 public:
  explicit MLAControlPlayerRight(const Location* input_location)
      : IControl("MLAControlPlayerRight"), location(input_location) {}

  void execute() override {
    location->get_races()->get_player()->go_right(location->get_size_x());
  }
};

#endif  // INCLUDE_ECS_SYSTEMS_CONTROLS_SYSTEM_LOOP_CONTROLS_MAIN_LOOP_ADVENTURE_SCENE_CONTROLS_MLACONTROLPLAYERRIGHT_H_
