//
// Created by vydra on 8/26/20.
//

#pragma once

#include "entities/location_entities/ambient_entities/Ambient.h"

class Throne : public Ambient {
 public:
  explicit Throne(unsigned input_x, unsigned input_y);
  ~Throne() override;
};
