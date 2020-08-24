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

  typedef std::function<void()> method;
  std::map<const char *, method> item_interact_map;
  std::map<const char *, method> ambient_interact_map;
  std::map<const char *, method>::iterator iterator;

 public:
  explicit InteractAbilitySystem();
  ~InteractAbilitySystem();

  bool try_interact_with(ILocationSystem *input_location_system);

  void interact_with_item(int input_index);
  method interact_with_coin();

  void interact_with_ambient(int input_index);
  method interact_with_door();
  method interact_with_east_gate();
  method interact_with_south_gate();
  method interact_with_west_gate();
};
