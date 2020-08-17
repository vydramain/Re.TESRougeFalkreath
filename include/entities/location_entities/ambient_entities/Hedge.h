//
// Created by vydra on 8/14/20.
//

#pragma once

#include "entities/location_entities/ambient_entities/Ambient.h"

class Hedge : public Ambient {
 public:
  explicit Hedge(unsigned input_x, unsigned input_y);
  ~Hedge() override;
};
