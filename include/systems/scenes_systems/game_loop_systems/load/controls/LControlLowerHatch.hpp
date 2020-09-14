//
// Created by vydra on 8/27/20.
//

#pragma once

#include "ILControl.h"
#include "entities/location_entities/ambient_entities/LowerHatch.hpp"

class LControlLowerHatch : public ILControl {
 public:
  explicit LControlLowerHatch(unsigned *input_x, unsigned *input_y, EntitiesSystem *input_entities_system)
      : ILControl("LControlLowerHatch", input_x, input_y, input_entities_system) {}
  ~LControlLowerHatch() override = default;

  void execute() override {
    entities_system->put_ambient(new LowerHatch(*new_x, *new_y));
  }
};