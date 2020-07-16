//
// Created by vydra on 16.07.2020.
//

#include "ecs/entities/creatures_entities/creatures_entity.h"


void creatures_entity::put_creature(creature_entity input_creature) {
    vec_creatures.push_back(input_creature);
}

creature_entity *creatures_entity::get_creature(unsigned int input_index) {
    return &vec_creatures[input_index];
}
