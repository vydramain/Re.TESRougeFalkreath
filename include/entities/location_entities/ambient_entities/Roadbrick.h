//
// Created by vydra on 8/14/20.
//

#pragma once

#include "entities/location_entities/ambient_entities/Ambient.h"

class Roadbrick : public Ambient {
 public:
  explicit Roadbrick(unsigned input_x, unsigned input_y);
  ~Roadbrick() override;
};
