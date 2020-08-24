//
// Created by vydra on 7/30/20.
//

#pragma once

#include "systems/controls_systems/IControl.h"
#include "systems/scenes_systems/game_loop_systems/location_systems/LocationSystem.h"
#include "systems/scenes_systems/game_loop_systems/location_systems/sub_systems/actions_systems/MoveSystem.hpp"

class GLAControlPlayerRight : public IControl {
 private:
  LocationSystem* location;

 public:
  explicit GLAControlPlayerRight(LocationSystem* input_location)
      : IControl("GLAControlPlayerRight"), location(input_location) {}

  void execute() override {
    if (MoveSystem::can_go_to(location, location->get_entities()->get_player()->get_current_x() + 1,
                              location->get_entities()->get_player()->get_current_y())) {
      location->get_entities()->get_player()->go_right(location->get_size_x());
    } else {
      location->get_entities()->get_player()->look_right();
    }
  }
};
