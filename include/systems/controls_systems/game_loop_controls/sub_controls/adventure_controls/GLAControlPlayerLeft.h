//
// Created by vydra on 7/30/20.
//

#pragma once

#include "systems/controls_systems/IControl.h"
#include "systems/location_systems/LocationSystem.h"

class GLAControlPlayerLeft : public IControl {
 private:
  LocationSystem* location;

 public:
  explicit GLAControlPlayerLeft(LocationSystem* input_location)
      : IControl("GLAControlPlayerLeft"), location(input_location) {}

  void execute() override {
    unsigned new_x = location->get_entities()->get_player()->get_current_x() - 1;
    unsigned new_y = location->get_entities()->get_player()->get_current_y();

    int magwerh_index = location->get_entities()->get_magwehr_index(new_x, new_y);
    int item_index = location->get_entities()->get_item_index(new_x, new_y);
    int ambient_index = location->get_entities()->get_ambient_index(new_x, new_y);

    if (ambient_index != -1 && location->get_entities()->get_ambient(ambient_index)->get_floor()) {
      ambient_index = -1;
    }

    if (item_index == -1 && ambient_index == -1 && magwerh_index == -1) {
      location->get_entities()->get_player()->go_left();
    } else {
      location->get_entities()->get_player()->look_left();
    }
  }
};