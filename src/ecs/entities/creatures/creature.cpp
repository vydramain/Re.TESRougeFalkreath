//
// Created by vydra on 15.07.2020.
//

#include "ecs/entities/creatures/creature.h"

void creature::go_up() {
    current_direction = DIRECTION_UP;
    current_y--;
}

void creature::go_down() {
    current_direction = DIRECTION_DOWN;
    current_y++;
}

void creature::go_left() {
    current_direction = DIRECTION_LEFT;
    current_x--;
}

void creature::go_right() {
    current_direction = DIRECTION_RIGHT;
    current_x++;
}
