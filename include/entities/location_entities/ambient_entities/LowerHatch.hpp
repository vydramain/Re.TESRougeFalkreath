//
// Created by vydra on 8/26/20.
//

#pragma once

#include "entities/location_entities/ambient_entities/Ambient.h"

class LowerHatch : public Ambient {
 public:
  explicit LowerHatch(unsigned input_x, unsigned input_y);
  ~LowerHatch() override;
};
