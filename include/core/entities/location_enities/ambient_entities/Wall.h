//
// Created by vydra on 8/14/20.
//

#pragma once

#include "core/entities/location_enities/ambient_entities/Ambient.h"

class Wall : public Ambient {
 public:
  explicit Wall(unsigned input_x, unsigned input_y);
  ~Wall() override;
};
