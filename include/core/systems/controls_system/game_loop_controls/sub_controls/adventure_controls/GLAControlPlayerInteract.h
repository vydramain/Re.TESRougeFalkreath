//
// Created by vydra on 8/3/20.
//

#pragma once

#include "core/systems/controls_system/IControl.h"
#include "ecs/systems/location_system/LocationSystem.h"

class GLAControlPlayerInteract : public IControl {
 private:
  LocationSystem* location;

 public:
  explicit GLAControlPlayerInteract(LocationSystem* input_location)
      : IControl("GLAControlPlayerInteract"), location(input_location) {}

  void execute() override {
    int index = location->get_items()->get_item_index(location->get_races()->get_player()->get_sight_x(),
                                                      location->get_races()->get_player()->get_sight_y());
    if (index != -1) {
      location->get_races()->get_player()->put_item(location->get_items()->remove_item(index));
    }
  }
};
