//
// Created by vydra on 8/3/20.
//

#include "ecs/entities/creatures_entities/beastfolk_race/Khadjiit.h"

Khadjiit::Khadjiit(const char *input_name, unsigned int input_current_x, unsigned int input_current_y,
                   unsigned int input_pocket)
    : Creature(input_name, input_current_x, input_current_y), Pocket(input_pocket) {}