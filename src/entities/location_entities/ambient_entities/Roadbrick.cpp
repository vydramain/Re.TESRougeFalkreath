//
// Created by vydra on 8/14/20.
//

#include "entities/location_entities/ambient_entities/Roadbrick.h"

Roadbrick::Roadbrick(unsigned int input_x, unsigned int input_y)
    : Ambient("Roadbrick", ".", 0xFF444444, input_x, input_y, true) {}

Roadbrick::~Roadbrick() = default;
