//
// Created by vydra on 8/24/20.
//

#pragma once

#include "ILControl.h"
#include "entities/location_entities/ambient_entities/WestGate.hpp"
#include "systems/scenes_systems/game_loop_systems/location_systems/sub_systems/entities_system/LocationsEntitiesSystem.h"

class LControlWestGate : public ILControl {
 public:
  explicit LControlWestGate(unsigned *input_x, unsigned *input_y, LocationsEntitiesSystem *input_entities_system)
      : ILControl("LControlWestGate", input_x, input_y, input_entities_system) {}
  ~LControlWestGate() override = default;

  void execute() override {
    entities_system->put_ambient(new WestGate(*new_x, *new_y));
  }
};
