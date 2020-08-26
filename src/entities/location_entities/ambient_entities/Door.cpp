//
// Created by vydra on 8/16/20.
//

#include "entities/location_entities/ambient_entities/Door.h"

Door::Door(unsigned int input_x, unsigned int input_y) : Ambient("Door", "┼", 0xff99692c, input_x, input_y) {}

Door::~Door() = default;
