//
// Created by vydra on 9/4/20.
//

#pragma once

#include "systems_new/scenes_systems/game_loop_systems/world/IWorldSystem.hpp"
#include "entities/location_entities/items_entities/Coin.h"

class AutoLootSystem {
 private:
  EntitiesSystem *entities_system;

 public:
  explicit AutoLootSystem(EntitiesSystem *input_entities_system);
  ~AutoLootSystem();

  void generate_group_of_coins(unsigned input_group_size, unsigned input_x_center_of_group,
                               unsigned input_y_center_of_group);
};