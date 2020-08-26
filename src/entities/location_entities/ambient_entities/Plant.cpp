//
// Created by vydra on 8/14/20.
//

#include "entities/location_entities/ambient_entities/Plant.h"

Plant::Plant(unsigned int input_x, unsigned int input_y) : Ambient("Plant", "p", 0xff4fd233, input_x, input_y) {}

Plant::~Plant() = default;
