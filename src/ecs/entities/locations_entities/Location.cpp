//
// Created by vydra on 15.07.2020.
//

#include "ecs/entities/locations_entities/Location.h"

const char *Location::get_name() const {
    return name;
}

unsigned int Location::get_size_x() const {
    return size_x;
}

unsigned int Location::get_size_y() const {
    return size_y;
}

Area *Location::get_current_area() const {
    return current_area;
}

Creatures *Location::get_current_creatures() const {
    return current_creatures;
}


void Location::set_name(const char *input_name) {
    Location::name = input_name;
}

void Location::set_size_x(unsigned int input_x) {
    size_x = input_x;
}

void Location::set_size_y(unsigned int input_y) {
    size_y = input_y;
}

void Location::set_current_area(Area *input_area) {
    current_area = input_area;
}

void Location::set_current_creatures(Creatures *input_creatures) {
    current_creatures = input_creatures;
}