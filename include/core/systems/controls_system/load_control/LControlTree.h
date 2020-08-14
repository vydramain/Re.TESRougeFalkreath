//
// Created by vydra on 8/14/20.
//

#pragma once

#include "core/entities/location_enities/ambient_entities/Tree.h"
#include "core/systems/controls_system/load_control/ILControl.h"
#include "core/systems/location_system/sub_systems/entities_system/LocationsEntitiesSystem.h"

class LControlTree : public ILControl {
 public:
  explicit LControlTree(unsigned *input_x, unsigned *input_y, LocationsEntitiesSystem *input_entities_system)
      : ILControl("LControlTree", input_x, input_y, input_entities_system) {}
  ~LControlTree() override = default;

  void execute() override {
    entities_system->put_ambient(new Tree(*new_x, *new_y));
  }
};
