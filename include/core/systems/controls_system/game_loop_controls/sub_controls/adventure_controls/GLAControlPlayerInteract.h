//
// Created by vydra on 8/3/20.
//

#pragma once

#include "core/systems/controls_system/IControl.h"
#include "ecs/systems/location_system/Location.h"

class GLAControlPlayerInteract : public IControl {
 private:
  Location* location;

 public:
  explicit GLAControlPlayerInteract(Location* input_location)
      : IControl("GLAControlPlayerInteract"), location(input_location) {}

  void execute() override {
    int index = location->get_items()->get_item_index(location->get_races()->get_player()->get_sight_x(),
                                                      location->get_races()->get_player()->get_sight_y());
    if (index != -1) {
      location->get_races()->get_player()->put_item(location->get_items()->remove_item(index));
    }
  }
};
