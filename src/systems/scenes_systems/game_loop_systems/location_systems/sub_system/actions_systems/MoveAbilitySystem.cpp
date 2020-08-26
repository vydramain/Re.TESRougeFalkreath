//
// Created by vydra on 8/25/20.
//

#include "systems/scenes_systems/game_loop_systems/location_systems/sub_systems/actions_systems/MoveAbilitySystem.hpp"

bool MoveAbilitySystem::can_move_to(ILocationSystem *input_location_system, unsigned int input_new_x,
                                  unsigned int input_new_y) {
  int magwerh_index = input_location_system->get_entities()->get_magwehr_index(input_new_x, input_new_y);
  int item_index = input_location_system->get_entities()->get_item_index(input_new_x, input_new_y);
  int ambient_index = input_location_system->get_entities()->get_ambient_index(input_new_x, input_new_y);

  if (ambient_index != -1 && input_location_system->get_entities()->get_ambient(ambient_index)->get_floor()) {
    ambient_index = -1;
  }

  return item_index == -1 && ambient_index == -1 && magwerh_index == -1;
}
