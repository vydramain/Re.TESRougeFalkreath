//
// Created by vydra on 8/14/20.
//

#pragma once

#include "core/entities/location_enities/ambient_entities/Water.h"
#include "core/systems/controls_system/load_control/ILControl.h"
#include "core/systems/location_system/sub_systems/entities_system/LocationsEntitiesSystem.h"

class LControlWater : public ILControl {
 public:
  explicit LControlWater(unsigned *input_x, unsigned *input_y, LocationsEntitiesSystem *input_entities_system)
      : ILControl("LControlWater", input_x, input_y, input_entities_system) {}
  ~LControlWater() override = default;

  void execute() override {
    entities_system->put_ambient(new Water(*new_x, *new_y));
  }
};
