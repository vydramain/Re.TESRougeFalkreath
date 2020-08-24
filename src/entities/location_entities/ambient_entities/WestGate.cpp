//
// Created by vydra on 8/24/20.
//

#include "entities/location_entities/ambient_entities/WestGate.hpp"

WestGate::WestGate(unsigned int input_x, unsigned int input_y)
    : Ambient("WestGate", "┼", 0xFF909090, input_x, input_y) {}

WestGate::~WestGate() = default;
