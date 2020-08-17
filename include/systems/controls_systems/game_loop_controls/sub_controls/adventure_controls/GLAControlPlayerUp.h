//
// Created by vydra on 7/30/20.
//

#pragma once

#include "systems/controls_systems/IControl.h"
#include "systems/location_systems/LocationSystem.h"

class GLAControlPlayerUp : public IControl {
 private:
  const LocationSystem* location;

 public:
  explicit GLAControlPlayerUp(const LocationSystem* input_location)
      : IControl("GLAControlPlayerUp"), location(input_location) {}

  void execute() override {
    unsigned new_x = location->get_entities()->get_player()->get_current_x();
    unsigned new_y = location->get_entities()->get_player()->get_current_y() - 1;

    int magwerh_index = location->get_entities()->get_magwehr_index(new_x, new_y);
    int item_index = location->get_entities()->get_item_index(new_x, new_y);
    int ambient_index = location->get_entities()->get_ambient_index(new_x, new_y);

    if (ambient_index != -1 && location->get_entities()->get_ambient(ambient_index)->get_floor()) {
      ambient_index = -1;
    }

    if (item_index == -1 && ambient_index == -1 && magwerh_index == -1) {
      location->get_entities()->get_player()->go_up();
    } else {
      location->get_entities()->get_player()->look_up();
    }
  }
};
