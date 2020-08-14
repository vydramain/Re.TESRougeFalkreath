//
// Created by vydra on 8/14/20.
//

#pragma once

#include "core/entities/location_enities/ambient_entities/Wall.h"
#include "core/systems/controls_system/load_control/ILControl.h"
#include "core/systems/location_system/sub_systems/entities_system/LocationsEntitiesSystem.h"

class LControlWall : public ILControl {
 public:
  explicit LControlWall(unsigned *input_x, unsigned *input_y, LocationsEntitiesSystem *input_entities_system)
      : ILControl("LControlWall", input_x, input_y, input_entities_system) {}
  ~LControlWall() override = default;

  void execute() override {
    entities_system->put_ambient(new Wall(*new_x, *new_y));
  }
};
