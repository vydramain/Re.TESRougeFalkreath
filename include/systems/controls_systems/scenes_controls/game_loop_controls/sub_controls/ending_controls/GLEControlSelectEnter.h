//
// Created by vydra on 7/31/20.
//

#pragma once

#include "systems/controls_systems/IControl.h"
#include "systems/scenes_systems/game_loop_systems/location_systems/LocationSystem.h"

class GLEControlSelectEnter : public IControl {
 private:
  LocationSystem *locaiton_system = nullptr;

 public:
  explicit GLEControlSelectEnter(LocationSystem *input_location_system)
      : IControl("GLEControlSelectEnter"), locaiton_system(input_location_system) {}
  ~GLEControlSelectEnter() override = default;

  void execute() override {}
};
