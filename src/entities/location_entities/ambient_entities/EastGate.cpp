//
// Created by vydra on 8/24/20.
//

#include "entities/location_entities/ambient_entities/EastGate.hpp"

EastGate::EastGate(unsigned int input_x, unsigned int input_y)
    : Ambient("EastGate", "┼", 0xFF909090, input_x, input_y) {}

EastGate::~EastGate() = default;
