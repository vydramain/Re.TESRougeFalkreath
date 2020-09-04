//
// Created by vydra on 9/2/20.
//

#pragma once

#include <string>
#include <vector>

#include "systems/scenes_systems/game_loop_systems/world/sub_systems/map_systems/IMapSystem.hpp"

class IWorldSystem {
 public:
  virtual ~IWorldSystem() = default;

  virtual void add_old_map(std::string input_map_address) = 0;
  virtual void add_new_map(std::string input_map_address) = 0;
  virtual void set_current_map(std::string input_name) = 0;
  virtual void set_ending_game(bool input_ending) = 0;

  virtual bool get_ending_game() = 0;
  virtual IMapSystem* get_current_map() = 0;
  virtual IMapSystem* get_current_map() const = 0;
  virtual std::vector<std::string>* get_maps_names() = 0;
};
