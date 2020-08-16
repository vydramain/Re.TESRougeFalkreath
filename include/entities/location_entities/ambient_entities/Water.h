//
// Created by vydra on 8/14/20.
//

#pragma once

#include "entities/location_entities/ambient_entities/Ambient.h"

class Water : public Ambient {
 public:
  explicit Water(unsigned input_x, unsigned input_y);
  ~Water() override;
};
