//
// Created by vydra on 8/25/20.
//

#include "systems/scenes_systems/game_loop_systems/actions/MoveAbilitySystem.hpp"

bool MoveAbilitySystem::can_move_to(IWorldSystem *input_world_system, unsigned int input_new_x,
                                    unsigned int input_new_y) {
  int sentient_index =
      input_world_system->get_current_map()->get_entities_system()->get_sentient_index(input_new_x, input_new_y);
  int magwerh_index =
      input_world_system->get_current_map()->get_entities_system()->get_magwehr_index(input_new_x, input_new_y);
  int item_index =
      input_world_system->get_current_map()->get_entities_system()->get_item_index(input_new_x, input_new_y);
  int ambient_index =
      input_world_system->get_current_map()->get_entities_system()->get_ambient_index(input_new_x, input_new_y);

  if (ambient_index != -1 &&
      input_world_system->get_current_map()->get_entities_system()->get_ambient(ambient_index)->get_floor()) {
    ambient_index = -1;
  }

  return item_index == -1 && ambient_index == -1 && magwerh_index == -1 && sentient_index == -1;
}
