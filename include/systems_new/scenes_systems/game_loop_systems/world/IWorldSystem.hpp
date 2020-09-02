//
// Created by vydra on 9/2/20.
//

#pragma once

#include <string>

#include "systems_new/scenes_systems/game_loop_systems/world/sub_systems/map_systems/IMapSystem.hpp"

class IWorldSystem {
 public:
  virtual ~IWorldSystem() = default;

  virtual void add_world(IMapSystem *input_map_system) = 0;
  virtual void set_current_map(std::string input_name) = 0;

  virtual IMapSystem* get_current_map() = 0;
  virtual IMapSystem* get_current_map() const = 0;
};