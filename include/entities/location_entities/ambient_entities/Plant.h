//
// Created by vydra on 8/14/20.
//

#pragma once

#include "entities/location_entities/ambient_entities/Ambient.h"

class Plant : public Ambient {
 public:
  explicit Plant(unsigned input_x, unsigned input_y);
  ~Plant() override;
};
