//
// Created by vydra on 8/25/20.
//

#include "systems/scenes_systems/game_loop_systems/location_systems/sub_systems/actions_systems/InteractAbilitySystem.hpp"

InteractAbilitySystem::InteractAbilitySystem() {
  data = new InteractAbilityData();

  item_interact_map["Coin"] = interact_with_coin();

  ambient_interact_map["Door"] = interact_with_door();
  ambient_interact_map["EastGate"] = interact_with_east_gate();
  ambient_interact_map["SouthGate"] = interact_with_south_gate();
  ambient_interact_map["WestGate"] = interact_with_west_gate();
}

InteractAbilitySystem::~InteractAbilitySystem() {
  location_system = nullptr;
}

bool InteractAbilitySystem::try_interact_with(ILocationSystem *input_location_system) {
  location_system = input_location_system;

  unsigned new_x = input_location_system->get_entities()->get_player()->get_sight_x();
  unsigned new_y = input_location_system->get_entities()->get_player()->get_sight_y();

  data->set_item_index(input_location_system->get_entities()->get_item_index(new_x, new_y));
  data->set_ambient_index(input_location_system->get_entities()->get_ambient_index(new_x, new_y));

  interact_with_item(data->get_item_index());
  interact_with_ambient(data->get_ambient_index());

  return data->get_item_index() == -1 && data->get_ambient_index() == -1;
}

void InteractAbilitySystem::interact_with_item(int input_index) {
  if (input_index != -1) {
    PseudoLogSystem::log("InteractAbilitySystem", location_system->get_entities()->get_player()->get_name(),
                         "interact with", location_system->get_entities()->get_item(input_index)->get_name());
    location_system->get_entities()->remove_item(input_index);
    iterator = item_interact_map.find(location_system->get_entities()->get_item(input_index)->get_name());
    iterator->second();
  }
}

InteractAbilitySystem::method InteractAbilitySystem::interact_with_coin() {
  location_system->get_entities()->get_player()->set_wallet(
      location_system->get_entities()->get_player()->get_wallet() + 1);
  return nullptr;
}

void InteractAbilitySystem::interact_with_ambient(int input_index) {
  if (input_index != -1) {
    PseudoLogSystem::log("InteractAbilitySystem", location_system->get_entities()->get_player()->get_name(),
                         "interact with", location_system->get_entities()->get_ambient(input_index)->get_name());
    iterator = ambient_interact_map.find(location_system->get_entities()->get_ambient(input_index)->get_name());
    iterator->second();
  }
}

InteractAbilitySystem::method InteractAbilitySystem::interact_with_door() {
  if (location_system->get_entities()->get_ambient(data->get_ambient_index())->get_floor()) {
    location_system->get_entities()->get_ambient(data->get_ambient_index())->set_floor(false);
    location_system->get_entities()->get_ambient(data->get_ambient_index())->set_tile("┼");
  } else {
    location_system->get_entities()->get_ambient(data->get_ambient_index())->set_floor(true);
    location_system->get_entities()->get_ambient(data->get_ambient_index())->set_tile("║");
  }
  return nullptr;
}

InteractAbilitySystem::method InteractAbilitySystem::interact_with_east_gate() {
  location_system->set_go_to_west_forest(true);
  return nullptr;
}

InteractAbilitySystem::method InteractAbilitySystem::interact_with_south_gate() {
  location_system->set_story_end(true);
  return nullptr;
}

InteractAbilitySystem::method InteractAbilitySystem::interact_with_west_gate() {
  location_system->set_go_to_falkreath(true);
  return nullptr;
}
