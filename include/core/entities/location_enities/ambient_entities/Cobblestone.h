//
// Created by vydra on 8/14/20.
//

#pragma once

#include "core/entities/location_enities/ambient_entities/Ambient.h"

class Cobblestone : public Ambient {
 public:
  explicit Cobblestone(unsigned input_x, unsigned input_y);
  ~Cobblestone() override;
};

