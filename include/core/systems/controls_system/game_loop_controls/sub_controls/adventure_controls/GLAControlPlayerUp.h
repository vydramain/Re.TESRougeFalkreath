//
// Created by vydra on 7/30/20.
//

#pragma once

#include "core/systems/controls_system/IControl.h"
#include "core/systems/location_system/LocationSystem.h"

class GLAControlPlayerUp : public IControl {
 private:
  const LocationSystem* location;

 public:
  explicit GLAControlPlayerUp(const LocationSystem* input_location)
      : IControl("GLAControlPlayerUp"), location(input_location) {}

  void execute() override {
    location->get_entities()->get_player()->go_up();
  }
};
