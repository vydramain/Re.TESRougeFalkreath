//
// Created by vydra on 8/14/20.
//

#include "core/entities/location_enities/ambient_entities/Wall.h"

Wall::Wall(unsigned int input_x, unsigned int input_y) :
      Ambient("Wall", '#', 0x88FFFFFF, input_x, input_y) {}

Wall::~Wall() = default;
