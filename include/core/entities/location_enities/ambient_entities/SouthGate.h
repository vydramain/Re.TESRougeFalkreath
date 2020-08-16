//
// Created by vydra on 8/16/20.
//

#pragma once

#include "core/entities/location_enities/ambient_entities/Ambient.h"

class SouthGate : public Ambient {
 public:
  SouthGate(unsigned input_x, unsigned input_y);
  ~SouthGate() override;
};
