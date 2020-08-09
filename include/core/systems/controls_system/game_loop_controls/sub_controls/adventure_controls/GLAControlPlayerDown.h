//
// Created by vydra on 7/30/20.
//

#pragma once

#include "core/systems/controls_system/IControl.h"
#include "ecs/systems/location_system/Location.h"

class GLAControlPlayerDown : public IControl {
 private:
  Location* location;

 public:
  explicit GLAControlPlayerDown(Location* input_location)
      : IControl("GLAControlPlayerDown"), location(input_location) {}

  void execute() override {
    location->get_races()->get_player()->go_down(location->get_area()->get_size_y());
  }
};
