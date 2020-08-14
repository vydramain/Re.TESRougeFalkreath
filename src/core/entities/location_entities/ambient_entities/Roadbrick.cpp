//
// Created by vydra on 8/14/20.
//

#include "core/entities/location_enities/ambient_entities/Roadbrick.h"

Roadbrick::Roadbrick(unsigned int input_x, unsigned int input_y)
    : Ambient("Roadbrick", '.', 0x77ffffff, input_x, input_y, true) {}

Roadbrick::~Roadbrick() = default;
