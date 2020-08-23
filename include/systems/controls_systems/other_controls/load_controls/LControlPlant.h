//
// Created by vydra on 8/14/20.
//

#pragma once

#include "systems/controls_systems/other_controls/load_controls/ILControl.h"
#include "entities/location_entities/ambient_entities/Plant.h"
#include "systems/scenes_systems/game_loop_systems/location_systems/sub_systems/entities_system/LocationsEntitiesSystem.h"

class LControlPlant : public ILControl {
 public:
  explicit LControlPlant(unsigned *input_x, unsigned *input_y, LocationsEntitiesSystem *input_entities_system)
      : ILControl("LControlPlant", input_x, input_y, input_entities_system) {}
  ~LControlPlant() override = default;

  void execute() override {
    entities_system->put_ambient(new Plant(*new_x, *new_y));
  }
};
