//
// Created by vydra on 8/25/20.
//

#pragma once

#include "systems/scenes_systems/game_loop_systems/world/IWorldSystem.hpp"

class MoveAbilitySystem {
 public:
  static bool can_move_to(IWorldSystem *input_location_system, unsigned int input_new_x, unsigned int input_new_y);
};
