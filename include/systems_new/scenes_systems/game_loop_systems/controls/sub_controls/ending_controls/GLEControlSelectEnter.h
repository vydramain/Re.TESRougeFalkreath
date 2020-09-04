//
// Created by vydra on 7/31/20.
//

#pragma once

#include "systems/scenes_systems/game_loop_systems/location_systems/LocationSystem.h"
#include "systems_new/IControl.h"
#include "systems_new/scenes_systems/game_loop_systems/world/IWorldSystem.hpp"

class GLEControlSelectEnter : public IControl {
 private:
  IWorldSystem *locaiton_system = nullptr;

 public:
  explicit GLEControlSelectEnter(IWorldSystem *input_location_system)
      : IControl("GLEControlSelectEnter"), locaiton_system(input_location_system) {}
  ~GLEControlSelectEnter() override = default;

  void execute() override {}
};
