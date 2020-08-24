//
// Created by vydra on 8/25/20.
//

#pragma once

#include "systems/scenes_systems/game_loop_systems/location_systems/ILocationSystem.h"

class MoveSystem {
 public:
  static bool can_go_to(ILocationSystem *input_location_system, unsigned int input_new_x, unsigned int input_new_y);

};