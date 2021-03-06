//
// Created by vydra on 9/4/20.
//

#include "systems/scenes_systems/game_loop_systems/load/sub_systems/auto_loot_system/AutoLootSystem.hpp"

AutoLootSystem::AutoLootSystem(EntitiesSystem *input_entities_system) {
  entities_system = input_entities_system;
}
AutoLootSystem::~AutoLootSystem() = default;

void AutoLootSystem::generate_group_of_coins(unsigned int input_group_size, unsigned int input_x_center_of_group,
                                             unsigned int input_y_center_of_group) {
  for (unsigned j = input_y_center_of_group - input_group_size - 1; j < input_y_center_of_group + input_group_size;
       j++) {
    for (unsigned i = input_x_center_of_group - input_group_size - 1; i < input_x_center_of_group + input_group_size;
         i++) {
      srand48(time(nullptr));
      unsigned temp = rand() % 10;
      if (temp < 4) {
        entities_system->put_item(new Coin(i, j));
      }
    }
  }
}
