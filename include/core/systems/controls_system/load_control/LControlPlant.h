//
// Created by vydra on 8/14/20.
//

#pragma once

#include "core/entities/location_enities/ambient_entities/Plant.h"
#include "core/systems/controls_system/load_control/ILControl.h"
#include "core/systems/location_system/sub_systems/entities_system/LocationsEntitiesSystem.h"

class LControlPlant : public ILControl {
 public:
  explicit LControlPlant(unsigned *input_x, unsigned *input_y, LocationsEntitiesSystem *input_entities_system)
      : ILControl("LControlPlant", input_x, input_y, input_entities_system) {}
  ~LControlPlant() override = default;

  void execute() override {
    entities_system->put_ambient(new Plant(*new_x, *new_y));
  }
};
