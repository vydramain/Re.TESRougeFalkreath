//
// Created by vydra on 8/25/20.
//

#include "systems/scenes_systems/game_loop_systems/actions/data/InteractAbilityData.hpp"

void InteractAbilityData::set_item_index(int input_index) {
  item_index = input_index;
}

void InteractAbilityData::set_ambient_index(int input_index) {
  ambient_index = input_index;
}

int InteractAbilityData::get_item_index() const {
  return item_index;
}

int InteractAbilityData::get_ambient_index() const {
  return ambient_index;
}
