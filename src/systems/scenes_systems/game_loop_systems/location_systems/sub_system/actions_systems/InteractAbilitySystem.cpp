//
// Created by vydra on 8/25/20.
//

#include "systems_new/scenes_systems/game_loop_systems/actions/InteractAbilitySystem.hpp"

#include <string>
#include <utility>

InteractAbilitySystem::InteractAbilitySystem() {
  data = new InteractAbilityData();

  item_interact_map.insert(std::pair<const char *, std::function<void()> >(
      "Coin", std::bind(&InteractAbilitySystem::interact_with_coin, this)));

  ambient_interact_map.insert(std::pair<const char *, std::function<void()> >(
      "Door", std::bind(&InteractAbilitySystem::interact_with_door, this)));
  ambient_interact_map.insert(std::pair<const char *, std::function<void()> >(
      "EastGate", std::bind(&InteractAbilitySystem::interact_with_east_gate, this)));
  ambient_interact_map.insert(std::pair<const char *, std::function<void()> >(
      "SouthGate", std::bind(&InteractAbilitySystem::interact_with_south_gate, this)));
  ambient_interact_map.insert(std::pair<const char *, std::function<void()> >(
      "WestGate", std::bind(&InteractAbilitySystem::interact_with_west_gate, this)));
  ambient_interact_map.insert(std::pair<const char *, std::function<void()> >(
      "UpperHatch", std::bind(&InteractAbilitySystem::interact_with_upper_hatch, this)));
  ambient_interact_map.insert(std::pair<const char *, std::function<void()> >(
      "LowerHatch", std::bind(&InteractAbilitySystem::interact_with_lower_hatch, this)));
  ambient_interact_map.insert(std::pair<const char *, std::function<void()> >(
      "CaveQuit", std::bind(&InteractAbilitySystem::interact_with_cave_quit, this)));
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
    interact_iterator = item_interact_map.find(location_system->get_entities()->get_item(input_index)->get_name());
    if (interact_iterator != item_interact_map.end()) {
      interact_iterator->second();
    }
  }
}

void InteractAbilitySystem::interact_with_coin() {
  location_system->get_entities()->get_player()->set_wallet(
      location_system->get_entities()->get_player()->get_wallet() + 1);
}

void InteractAbilitySystem::interact_with_ambient(int input_index) {
  if (input_index != -1) {
    PseudoLogSystem::log("InteractAbilitySystem", location_system->get_entities()->get_player()->get_name(),
                         "interact with", location_system->get_entities()->get_ambient(input_index)->get_name());
    interact_iterator =
        ambient_interact_map.find(location_system->get_entities()->get_ambient(input_index)->get_name());
    if (interact_iterator != ambient_interact_map.end()) {
      interact_iterator->second();
    }
  }
}

void InteractAbilitySystem::interact_with_nothing() {}

void InteractAbilitySystem::interact_with_door() {
  if (location_system->get_entities()->get_ambient(data->get_ambient_index())->get_floor()) {
    location_system->get_entities()->get_ambient(data->get_ambient_index())->set_floor(false);
    location_system->get_entities()->get_ambient(data->get_ambient_index())->set_tile("┼");
  } else {
    location_system->get_entities()->get_ambient(data->get_ambient_index())->set_floor(true);
    location_system->get_entities()->get_ambient(data->get_ambient_index())->set_tile("║");
  }
}

void InteractAbilitySystem::interact_with_east_gate() {
  location_system->set_go_to_west_forest_form_falkreth(true);
}

void InteractAbilitySystem::interact_with_south_gate() {
  location_system->set_story_end(true);
}

void InteractAbilitySystem::interact_with_west_gate() {
  location_system->set_go_to_falkreath_from_west_forest(true);
}

void InteractAbilitySystem::interact_with_upper_hatch() {
  location_system->set_go_to_bloodlet_throne_from_west_forest(true);
}

void InteractAbilitySystem::interact_with_lower_hatch() {
  location_system->set_go_to_west_forest_from_bloodlet_throne_by_hatch(true);
}

void InteractAbilitySystem::interact_with_cave_quit() {
  location_system->set_go_to_west_forest_from_bloodlet_throne_by_cave(true);
}
