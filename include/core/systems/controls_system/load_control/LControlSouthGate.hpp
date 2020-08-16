//
// Created by vydra on 8/16/20.
//

#pragma once

#include "core/entities/location_enities/ambient_entities/SouthGate.h"
#include "core/systems/controls_system/load_control/ILControl.h"
#include "core/systems/location_system/sub_systems/entities_system/LocationsEntitiesSystem.h"

class LControlSouthGate : public ILControl {
 public:
  explicit LControlSouthGate(unsigned *input_x, unsigned *input_y, LocationsEntitiesSystem *input_entities_system)
      : ILControl("LControlRoadbrick", input_x, input_y, input_entities_system) {}
  ~LControlSouthGate() override = default;

  void execute() override {
    entities_system->put_ambient(new SouthGate(*new_x, *new_y));
  }
};
