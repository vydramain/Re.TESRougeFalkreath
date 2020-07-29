//
// Created by vydra on 16.07.2020.
//

#include "ecs/entities/creatures_entities/Creatures.h"


void Creatures::put_creature(Creature input_creature) {
    vec_creatures.push_back(input_creature);
}

Creature *Creatures::get_creature(unsigned int input_index) {
    Creature *pointer = vec_creatures.data();
    return &pointer[input_index];
}

const Creature *Creatures::get_creature(unsigned int input_index) const {
    const Creature *pointer = vec_creatures.data();
    return &pointer[input_index];
}

unsigned Creatures::get_size() const {
    return vec_creatures.size();
}

