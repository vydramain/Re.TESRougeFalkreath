//
// Created by vydra on 7/30/20.
//

#pragma once

#include "core/systems/controls_system/IControl.h"
#include "core/systems/location_system/LocationSystem.h"

class GLAControlPlayerDown : public IControl {
 private:
  LocationSystem* location;

 public:
  explicit GLAControlPlayerDown(LocationSystem* input_location)
      : IControl("GLAControlPlayerDown"), location(input_location) {}

  void execute() override {
    location->get_entities()->get_player()->go_down(location->get_area()->get_size_y());
  }
};
