//
// Created by vydra on 8/25/20.
//

#include "systems/scenes_systems/game_loop_systems/actions/InteractAbilitySystem.hpp"

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
  world_system = nullptr;
}

bool InteractAbilitySystem::try_interact_with(IWorldSystem *input_world_system) {
  world_system = input_world_system;

  unsigned new_x = world_system->get_current_map()->get_entities_system()->get_player()->get_sight_x();
  unsigned new_y = world_system->get_current_map()->get_entities_system()->get_player()->get_sight_y();

  data->set_item_index(input_world_system->get_current_map()->get_entities_system()->get_item_index(new_x, new_y));
  data->set_ambient_index(
      input_world_system->get_current_map()->get_entities_system()->get_ambient_index(new_x, new_y));

  interact_with_item(data->get_item_index());
  interact_with_ambient(data->get_ambient_index());

  return data->get_item_index() == -1 && data->get_ambient_index() == -1;
}

void InteractAbilitySystem::interact_with_item(int input_index) {
  if (input_index != -1) {
    PseudoLogSystem::log(
        "InteractAbilitySystem", world_system->get_current_map()->get_entities_system()->get_player()->get_name(),
        "interact with", world_system->get_current_map()->get_entities_system()->get_item(input_index)->get_name());
    world_system->get_current_map()->get_entities_system()->remove_item(input_index);
    interact_iterator = item_interact_map.find(
        world_system->get_current_map()->get_entities_system()->get_item(input_index)->get_name());
    if (interact_iterator != item_interact_map.end()) {
      interact_iterator->second();
    }
  }
}

void InteractAbilitySystem::interact_with_coin() {
  world_system->get_current_map()->get_entities_system()->get_player()->set_wallet(
      world_system->get_current_map()->get_entities_system()->get_player()->get_wallet() + 1);
}

void InteractAbilitySystem::interact_with_ambient(int input_index) {
  if (input_index != -1) {
    PseudoLogSystem::log(
        "InteractAbilitySystem", world_system->get_current_map()->get_entities_system()->get_player()->get_name(),
        "interact with", world_system->get_current_map()->get_entities_system()->get_ambient(input_index)->get_name());
    interact_iterator = ambient_interact_map.find(
        world_system->get_current_map()->get_entities_system()->get_ambient(input_index)->get_name());
    if (interact_iterator != ambient_interact_map.end()) {
      interact_iterator->second();
    }
  }
}

void InteractAbilitySystem::interact_with_nothing() {}

void InteractAbilitySystem::interact_with_door() {
  if (world_system->get_current_map()->get_entities_system()->get_ambient(data->get_ambient_index())->get_floor()) {
    world_system->get_current_map()->get_entities_system()->get_ambient(data->get_ambient_index())->set_floor(false);
    world_system->get_current_map()->get_entities_system()->get_ambient(data->get_ambient_index())->set_tile("┼");
  } else {
    world_system->get_current_map()->get_entities_system()->get_ambient(data->get_ambient_index())->set_floor(true);
    world_system->get_current_map()->get_entities_system()->get_ambient(data->get_ambient_index())->set_tile("║");
  }
}

void InteractAbilitySystem::interact_with_east_gate() {
  auto *player = world_system->get_current_map()->get_entities_system()->remove_player();
  world_system->set_current_map("WestForest");
  world_system->get_current_map()->get_entities_system()->put_player(player);
  world_system->get_current_map()->get_entities_system()->get_player()->set_current_x(3);
  world_system->get_current_map()->get_entities_system()->get_player()->set_current_y(13);
}

void InteractAbilitySystem::interact_with_south_gate() {
  // Endgame
  world_system->set_ending_game(true);
}

void InteractAbilitySystem::interact_with_west_gate() {
  auto *player = world_system->get_current_map()->get_entities_system()->remove_player();
  world_system->set_current_map("Falkreath");
  world_system->get_current_map()->get_entities_system()->put_player(player);
  world_system->get_current_map()->get_entities_system()->get_player()->set_current_x(72);
  world_system->get_current_map()->get_entities_system()->get_player()->set_current_y(13);
}

void InteractAbilitySystem::interact_with_upper_hatch() {
  auto *player = world_system->get_current_map()->get_entities_system()->remove_player();
  world_system->set_current_map("BloodletThrone");
  world_system->get_current_map()->get_entities_system()->put_player(player);
  world_system->get_current_map()->get_entities_system()->get_player()->set_current_x(5);
  world_system->get_current_map()->get_entities_system()->get_player()->set_current_y(2);
}

void InteractAbilitySystem::interact_with_lower_hatch() {
  auto *player = world_system->get_current_map()->get_entities_system()->remove_player();
  world_system->set_current_map("WestForest");
  world_system->get_current_map()->get_entities_system()->put_player(player);
  world_system->get_current_map()->get_entities_system()->get_player()->set_current_x(181);
  world_system->get_current_map()->get_entities_system()->get_player()->set_current_y(95);
}

void InteractAbilitySystem::interact_with_cave_quit() {
  auto *player = world_system->get_current_map()->get_entities_system()->remove_player();
  world_system->set_current_map("WestForest");
  world_system->get_current_map()->get_entities_system()->put_player(player);
  world_system->get_current_map()->get_entities_system()->get_player()->set_current_x(218); // 248
  world_system->get_current_map()->get_entities_system()->get_player()->set_current_y(96);
}
