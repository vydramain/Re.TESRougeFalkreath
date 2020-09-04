//
// Created by vydra on 7/30/20.
//

#pragma once

#include "systems/scenes_systems/game_loop_systems/location_systems/LocationSystem.h"
#include "systems_new/IControl.h"
#include "systems_new/scenes_systems/game_loop_systems/actions/MoveAbilitySystem.hpp"

class GLAControlPlayerRight : public IControl {
 private:
  LocationSystem* location;

 public:
  explicit GLAControlPlayerRight(LocationSystem* input_location)
      : IControl("GLAControlPlayerRight"), location(input_location) {}

  void execute() override {
    if (MoveAbilitySystem::can_move_to(location, location->get_entities()->get_player()->get_current_x() + 1,
                                       location->get_entities()->get_player()->get_current_y())) {
      location->get_entities()->get_player()->go_right(location->get_size_x());
    } else {
      location->get_entities()->get_player()->look_right();
    }
  }
};
