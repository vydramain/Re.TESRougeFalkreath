//
// Created by vydra on 8/16/20.
//

#pragma once

#include "core/entities/location_enities/ambient_entities/Door.h"
#include "core/systems/controls_system/load_control/ILControl.h"
#include "core/systems/location_system/sub_systems/entities_system/LocationsEntitiesSystem.h"

class LControlDoor : public ILControl {
 public:
  explicit LControlDoor(unsigned *input_x, unsigned *input_y, LocationsEntitiesSystem *input_entities_system)
      : ILControl("LControlHedge", input_x, input_y, input_entities_system) {}
  ~LControlDoor() override = default;

  void execute() override {
    entities_system->put_ambient(new Door(*new_x, *new_y));
  }
};
