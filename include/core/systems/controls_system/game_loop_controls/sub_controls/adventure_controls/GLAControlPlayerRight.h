//
// Created by vydra on 7/30/20.
//

#pragma once

#include "core/systems/controls_system/IControl.h"
#include "core/systems/location_system/LocationSystem.h"

class GLAControlPlayerRight : public IControl {
 private:
  const LocationSystem* location;

 public:
  explicit GLAControlPlayerRight(const LocationSystem* input_location)
      : IControl("GLAControlPlayerRight"), location(input_location) {}

  void execute() override {
    unsigned new_x = location->get_entities()->get_player()->get_current_x() + 1;
    unsigned new_y = location->get_entities()->get_player()->get_current_y();

    int magwerh_index = location->get_entities()->get_magwehr_index(new_x, new_y);
    int item_index = location->get_entities()->get_item_index(new_x, new_y);
    int ambient_index = location->get_entities()->get_ambient_index(new_x, new_y);

    if (ambient_index != -1 && location->get_entities()->get_ambient(ambient_index)->get_floor()) {
      ambient_index = -1;
    }

    if (item_index == -1 && ambient_index == -1 && magwerh_index == -1) {
      location->get_entities()->get_player()->go_right(location->get_size_x());
    } else {
      location->get_entities()->get_player()->look_right();
    }
  }
};
