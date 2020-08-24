//
// Created by vydra on 8/24/20.
//

#pragma once

#include "entities/location_entities/ambient_entities/Ambient.h"

class EastGate : public Ambient {
 public:
  EastGate(unsigned input_x, unsigned input_y);
  ~EastGate() override;
};
