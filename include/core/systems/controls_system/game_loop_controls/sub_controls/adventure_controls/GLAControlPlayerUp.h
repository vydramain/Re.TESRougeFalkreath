//
// Created by vydra on 7/30/20.
//

#pragma once

#include "core/systems/controls_system/IControl.h"
#include "ecs/systems/location_system/LocationSystem.h"

class GLAControlPlayerUp : public IControl {
 private:
  const LocationSystem* location;

 public:
  explicit GLAControlPlayerUp(const LocationSystem* input_location)
      : IControl("GLAControlPlayerUp"), location(input_location) {}

  void execute() override {
    location->get_races()->get_player()->go_up();
  }
};
