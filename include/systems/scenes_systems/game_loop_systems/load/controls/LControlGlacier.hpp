//
// Created by vydra on 8/27/20.
//

#pragma once

#include "ILControl.h"
#include "entities/location_entities/ambient_entities/Glacier.hpp"

class LControlGlacier : public ILControl {
 public:
  explicit LControlGlacier(unsigned *input_x, unsigned *input_y, EntitiesSystem *input_entities_system)
      : ILControl("LControlGlacier", input_x, input_y, input_entities_system) {}
  ~LControlGlacier() override = default;

  void execute() override {
    entities_system->put_ambient(new Glacier(*new_x, *new_y));
  }
};