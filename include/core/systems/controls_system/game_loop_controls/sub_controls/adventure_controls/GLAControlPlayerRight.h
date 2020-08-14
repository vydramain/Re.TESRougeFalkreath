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
    location->get_entities()->get_player()->go_right(location->get_size_x());
  }
};
