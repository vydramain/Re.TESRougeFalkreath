//
// Created by vydra on 8/14/20.
//

#pragma once

#include "systems/controls_systems/load_controls/ILControl.h"
#include "entities/location_entities/ambient_entities/Water.h"
#include "systems/location_systems/sub_systems/entities_system/LocationsEntitiesSystem.h"

class LControlWater : public ILControl {
 public:
  explicit LControlWater(unsigned *input_x, unsigned *input_y, LocationsEntitiesSystem *input_entities_system)
      : ILControl("LControlWater", input_x, input_y, input_entities_system) {}
  ~LControlWater() override = default;

  void execute() override {
    entities_system->put_ambient(new Water(*new_x, *new_y));
  }
};
