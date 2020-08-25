//
// Created by vydra on 8/25/20.
//

#pragma once

#include <functional>
#include <map>

#include "adds/log_systems/PseudoLogSystem.hpp"
#include "systems/scenes_systems/game_loop_systems/location_systems/ILocationSystem.h"
#include "systems/scenes_systems/game_loop_systems/location_systems/sub_systems/actions_systems/data/InteractAbilityData.hpp"

class InteractAbilitySystem {
 private:
  InteractAbilityData *data = nullptr;
  ILocationSystem *location_system = nullptr;

  std::map<const char *, void*()> item_interact_map;
  std::map<const char *, void*()> ambient_interact_map;
  std::map<const char *, void*()>::iterator iterator;

 public:
  explicit InteractAbilitySystem();
  ~InteractAbilitySystem();

  bool try_interact_with(ILocationSystem *input_location_system);

  void interact_with_item(int input_index);
  void interact_with_coin();

  void interact_with_ambient(int input_index);
  void interact_with_door();
  void interact_with_east_gate();
  void interact_with_south_gate();
  void interact_with_west_gate();

  void (*interact_coin)() = interact_with_coin();
};
