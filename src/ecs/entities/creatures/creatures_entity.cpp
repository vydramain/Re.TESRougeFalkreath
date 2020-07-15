//
// Created by vydra on 16.07.2020.
//

#include "ecs/entities/creatures/g_creatures.h"

void g_creatures::put_creature(creature input_creature) {
    vec_creatures.push_back(input_creature);
}

creature *g_creatures::get_creature(unsigned int input_index) {
    return &vec_creatures[input_index];
}
