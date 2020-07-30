//
// Created by vydra on 15.07.2020.
//

#include "ecs/entities/Map.h"

unsigned Map::get_size_x() {
    return size_x;
}

unsigned Map::get_size_y() {
    return size_y;
}

char Map::get_cell(unsigned input_x, unsigned input_y) {
    return data[input_x][input_y];
}
