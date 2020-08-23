//
// Created by vydra on 7/30/20.
//

#pragma once

#include "entities/location_entities/ambient_entities/Roadbrick.h"
#include "systems/controls_systems/IControl.h"
#include "systems/scenes_systems/game_loop_systems/location_systems/LocationSystem.h"

class GLAControlPlayerDown : public IControl {
 private:
  LocationSystem* location;

 public:
  explicit GLAControlPlayerDown(LocationSystem* input_location)
      : IControl("GLAControlPlayerDown"), location(input_location) {}

  void execute() override {
    unsigned new_x = location->get_entities()->get_player()->get_current_x();
    unsigned new_y = location->get_entities()->get_player()->get_current_y() + 1;

    int magwerh_index = location->get_entities()->get_magwehr_index(new_x, new_y);
    int item_index = location->get_entities()->get_item_index(new_x, new_y);
    int ambient_index = location->get_entities()->get_ambient_index(new_x, new_y);

    if (ambient_index != -1 && location->get_entities()->get_ambient(ambient_index)->get_floor()) {
      ambient_index = -1;
    }

    if (item_index == -1 && ambient_index == -1 && magwerh_index == -1) {
      location->get_entities()->get_player()->go_down(location->get_size_y());
    } else {
      location->get_entities()->get_player()->look_down();
    }
  }
};
