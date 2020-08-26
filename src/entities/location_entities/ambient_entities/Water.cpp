//
// Created by vydra on 8/14/20.
//

#include "entities/location_entities/ambient_entities/Water.h"

Water::Water(unsigned int input_x, unsigned int input_y) :
      Ambient("Water", "~", 0xFF2a7cbb, input_x, input_y) {}

Water::~Water() = default;
