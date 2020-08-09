//
// Created by vydra on 7/30/20.
//

#pragma once

#include "core/systems/controls_system/IControl.h"
#include "ecs/systems/location_system/LocationSystem.h"

class GLAControlPlayerLeft : public IControl {
 private:
  LocationSystem* location;

 public:
  explicit GLAControlPlayerLeft(LocationSystem* input_location)
      : IControl("GLAControlPlayerLeft"), location(input_location) {}

  void execute() override {
    location->get_races()->get_player()->go_left();
  }
};
