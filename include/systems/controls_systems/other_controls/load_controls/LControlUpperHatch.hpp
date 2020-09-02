//
// Created by vydra on 8/26/20.
//

#pragma once

#include "entities/location_entities/ambient_entities/UpperHatch.hpp"
#include "systems/controls_systems/other_controls/load_controls/ILControl.h"

class LControlUpperHatch : public ILControl {
 public:
  explicit LControlUpperHatch(unsigned *input_x, unsigned *input_y, EntitiesSystem *input_entities_system)
      : ILControl("LControlUpperHatch", input_x, input_y, input_entities_system) {}
  ~LControlUpperHatch() override = default;

  void execute() override {
    entities_system->put_ambient(new UpperHatch(*new_x, *new_y));
  }
};
