//
// Created by vydra on 8/26/20.
//

#pragma once

#include "entities/location_entities/ambient_entities/Ambient.h"

class UpperHatch : public Ambient {
 public:
  explicit UpperHatch(unsigned input_x, unsigned input_y);
  ~UpperHatch() override;
};
