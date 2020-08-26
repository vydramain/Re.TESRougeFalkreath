//
// Created by vydra on 8/27/20.
//

#pragma once

#include "entities/location_entities/ambient_entities/Glacier.hpp"
#include "systems/controls_systems/other_controls/load_controls/ILControl.h"

class LControlGlacier : public ILControl {
 public:
  explicit LControlGlacier(unsigned *input_x, unsigned *input_y, LocationsEntitiesSystem *input_entities_system)
      : ILControl("LControlGlacier", input_x, input_y, input_entities_system) {}
  ~LControlGlacier() override = default;

  void execute() override {
    entities_system->put_ambient(new Glacier(*new_x, *new_y));
  }
};