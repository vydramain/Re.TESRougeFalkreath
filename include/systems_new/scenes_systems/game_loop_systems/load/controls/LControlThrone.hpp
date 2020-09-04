//
// Created by vydra on 8/27/20.
//

#pragma once

#include "ILControl.h"
#include "entities/location_entities/ambient_entities/Throne.hpp"

class LControlThrone : public ILControl {
 public:
  explicit LControlThrone(unsigned *input_x, unsigned *input_y, EntitiesSystem *input_entities_system)
      : ILControl("LControlThrone", input_x, input_y, input_entities_system) {}
  ~LControlThrone() override = default;

  void execute() override {
    entities_system->put_ambient(new Throne(*new_x, *new_y));
  }
};