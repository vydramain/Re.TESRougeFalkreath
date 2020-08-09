//
// Created by vydra on 7/30/20.
//

#pragma once

#include "core/systems/controls_system/IControl.h"
#include "ecs/systems/location_system/Location.h"

class GLAControlPlayerRight : public IControl {
 private:
  const Location* location;

 public:
  explicit GLAControlPlayerRight(const Location* input_location)
      : IControl("GLAControlPlayerRight"), location(input_location) {}

  void execute() override {
    location->get_races()->get_player()->go_right(location->get_area()->get_size_x());
  }
};
