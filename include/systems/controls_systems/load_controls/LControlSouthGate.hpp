//
// Created by vydra on 8/16/20.
//

#pragma once

#include "entities/location_entities/ambient_entities/SouthGate.h"
#include "systems/controls_systems/load_controls/ILControl.h"
#include "systems/location_systems/sub_systems/entities_system/LocationsEntitiesSystem.h"

class LControlSouthGate : public ILControl {
 public:
  explicit LControlSouthGate(unsigned *input_x, unsigned *input_y, LocationsEntitiesSystem *input_entities_system)
      : ILControl("LControlRoadbrick", input_x, input_y, input_entities_system) {}
  ~LControlSouthGate() override = default;

  void execute() override {
    entities_system->put_ambient(new SouthGate(*new_x, *new_y));
  }
};
