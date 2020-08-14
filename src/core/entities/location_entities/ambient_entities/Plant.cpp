//
// Created by vydra on 8/14/20.
//

#include "core/entities/location_enities/ambient_entities/Plant.h"

Plant::Plant(unsigned int input_x, unsigned int input_y) : Ambient("Plant", 'p', 0xff80ff60, input_x, input_y) {}

Plant::~Plant() = default;
