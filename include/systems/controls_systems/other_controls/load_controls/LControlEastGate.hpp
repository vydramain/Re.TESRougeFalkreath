//
// Created by vydra on 8/24/20.
//

#pragma once

#include "ILControl.h"
#include "entities/location_entities/ambient_entities/EastGate.hpp"
#include "systems/scenes_systems/game_loop_systems/location_systems/sub_systems/entities_system/LocationsEntitiesSystem.h"

class LControlEastGate : public ILControl {
 public:
  explicit LControlEastGate(unsigned *input_x, unsigned *input_y, LocationsEntitiesSystem *input_entities_system)
      : ILControl("LControlEastGate", input_x, input_y, input_entities_system) {}
  ~LControlEastGate() override = default;

  void execute() override {
    entities_system->put_ambient(new EastGate(*new_x, *new_y));
  }
};
