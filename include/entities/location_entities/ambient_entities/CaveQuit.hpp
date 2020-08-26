//
// Created by vydra on 8/26/20.
//

#pragma once

#include "entities/location_entities/ambient_entities/Ambient.h"

class CaveQuit : public Ambient {
 public:
  explicit CaveQuit(unsigned input_x, unsigned input_y);
  ~CaveQuit() override;
};
