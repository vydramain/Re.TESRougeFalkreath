//
// Created by vydra on 8/16/20.
//

#pragma once

#include "core/entities/location_enities/ambient_entities/Ambient.h"

class Door : public Ambient {
 public:
  Door(unsigned input_x, unsigned input_y);
  ~Door() override;
};
