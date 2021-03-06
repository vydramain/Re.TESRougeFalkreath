//
// Created by vydra on 8/25/20.
//

#pragma once

#include <functional>
#include <map>
#include <string>
#include <utility>

#include "adds/log_systems/PseudoLogSystem.hpp"
#include "systems/scenes_systems/game_loop_systems/actions/data/InteractAbilityData.hpp"
#include "systems/scenes_systems/game_loop_systems/world/IWorldSystem.hpp"

class InteractAbilitySystem {
 private:
  InteractAbilityData *data = nullptr;
  IWorldSystem *world_system = nullptr;

  std::map<std::string, std::function<void()>> item_interact_map;
  std::map<std::string, std::function<void()>> ambient_interact_map;
  std::map<std::string, std::function<void()>>::iterator interact_iterator;

 public:
  explicit InteractAbilitySystem();
  ~InteractAbilitySystem();

  bool try_interact_with(IWorldSystem *input_world_system);

  void interact_with_item(int input_index);
  void interact_with_coin();

  void interact_with_ambient(int input_index);
  void interact_with_nothing();
  void interact_with_door();
  void interact_with_east_gate();
  void interact_with_south_gate();
  void interact_with_west_gate();
  void interact_with_upper_hatch();
  void interact_with_lower_hatch();
  void interact_with_cave_quit();
};
