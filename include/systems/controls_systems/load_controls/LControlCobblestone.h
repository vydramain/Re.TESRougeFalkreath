//
// Created by vydra on 8/14/20.
//

#pragma once

#include "entities/location_entities/ambient_entities/Cobblestone.h"
#include "systems/controls_systems/load_controls/ILControl.h"
#include "systems/location_systems/sub_systems/entities_system/LocationsEntitiesSystem.h"

class LControlCobblestone : public ILControl {
 public:
  explicit LControlCobblestone(unsigned *input_x, unsigned *input_y, LocationsEntitiesSystem *input_entities_system)
      : ILControl("LControlCobblestone", input_x, input_y, input_entities_system) {}
  ~LControlCobblestone() override = default;

  void execute() override {
    entities_system->put_ambient(new Cobblestone(*new_x, *new_y));
  }
};
