//
// Created by vydra on 8/26/20.
//

#pragma once

#include "entities/location_entities/ambient_entities/Ambient.h"

class Glacier : public Ambient {
 public:
  explicit Glacier(unsigned input_x, unsigned input_y);
  ~Glacier() override;
};
