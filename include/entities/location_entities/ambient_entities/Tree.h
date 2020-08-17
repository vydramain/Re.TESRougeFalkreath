//
// Created by vydra on 8/14/20.
//

#pragma once

#include "entities/location_entities/ambient_entities/Ambient.h"

class Tree : public Ambient {
 public:
  explicit Tree(unsigned input_x, unsigned input_y);
  ~Tree() override;
};
