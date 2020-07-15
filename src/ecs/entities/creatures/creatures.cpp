//
// Created by vydra on 16.07.2020.
//

#include "ecs/entities/creatures/creatures.h"

void creatures::put_creature(creature input_creature) {
    vec_creatures.push_back(input_creature);
}

creature *creatures::get_creature(unsigned int input_index) {
    return &vec_creatures[input_index];
}
