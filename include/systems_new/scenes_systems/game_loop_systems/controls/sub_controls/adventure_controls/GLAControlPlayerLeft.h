//
// Created by vydra on 7/30/20.
//

#pragma once

#include "systems/controls_systems/IControl.h"
#include "systems/scenes_systems/game_loop_systems/location_systems/LocationSystem.h"
#include "systems/scenes_systems/game_loop_systems/location_systems/sub_systems/actions_systems/MoveAbilitySystem.hpp"

class GLAControlPlayerLeft : public IControl {
 private:
  LocationSystem* location;

 public:
  explicit GLAControlPlayerLeft(LocationSystem* input_location)
      : IControl("GLAControlPlayerLeft"), location(input_location) {}

  void execute() override {
    if (MoveAbilitySystem::can_move_to(location, location->get_entities()->get_player()->get_current_x() - 1,
                                       location->get_entities()->get_player()->get_current_y())) {
      location->get_entities()->get_player()->go_left();
    } else {
      location->get_entities()->get_player()->look_left();
    }
  }
};
