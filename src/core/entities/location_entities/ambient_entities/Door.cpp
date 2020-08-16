//
// Created by vydra on 8/16/20.
//

#include "core/entities/location_enities/ambient_entities/Door.h"

Door::Door(unsigned int input_x, unsigned int input_y) : Ambient("Door", "┼", 0xff6a4000, input_x, input_y) {}

Door::~Door() = default;
