//
// Created by vydra on 8/14/20.
//

#include "entities/location_entities/ambient_entities/Cobblestone.h"

Cobblestone::Cobblestone(unsigned int input_x, unsigned int input_y) :
      Ambient("Cobblestone", "c", 0xFF999999, input_x, input_y) {}

Cobblestone::~Cobblestone() = default;
