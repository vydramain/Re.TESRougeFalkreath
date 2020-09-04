//
// Created by vydra on 7/30/20.
//

#pragma once

#include "systems/scenes_systems/game_loop_systems/location_systems/LocationSystem.h"
#include "systems_new/IControl.h"
#include "systems_new/scenes_systems/game_loop_systems/actions/MoveAbilitySystem.hpp"

class GLAControlPlayerUp : public IControl {
 private:
  LocationSystem* location;

 public:
  explicit GLAControlPlayerUp(LocationSystem* input_location)
      : IControl("GLAControlPlayerUp"), location(input_location) {}

  void execute() override {
    if (MoveAbilitySystem::can_move_to(location, location->get_entities()->get_player()->get_current_x(),
                                       location->get_entities()->get_player()->get_current_y() - 1)) {
      location->get_entities()->get_player()->go_up();
    } else {
      location->get_entities()->get_player()->look_up();
    }
  }
};
