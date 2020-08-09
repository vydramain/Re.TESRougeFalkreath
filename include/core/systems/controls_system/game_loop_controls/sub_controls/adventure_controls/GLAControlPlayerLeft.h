//
// Created by vydra on 7/30/20.
//

#pragma once

#include "core/systems/controls_system/IControl.h"
#include "ecs/systems/location_system/Location.h"

class GLAControlPlayerLeft : public IControl {
 private:
  Location* location;

 public:
  explicit GLAControlPlayerLeft(Location* input_location)
      : IControl("GLAControlPlayerLeft"), location(input_location) {}

  void execute() override {
    location->get_races()->get_player()->go_left();
  }
};
