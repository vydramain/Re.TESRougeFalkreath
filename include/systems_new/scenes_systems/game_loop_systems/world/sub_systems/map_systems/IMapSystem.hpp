//
// Created by vydra on 9/2/20.
//

#pragma once

#include <string>

#include "systems_new/scenes_systems/game_loop_systems/world/sub_systems/map_systems/entities_system/EntitiesSystem.h"

class IMapSystem {
 public:
  virtual ~IMapSystem() = default;

  virtual std::string get_name() = 0;
  virtual unsigned get_size_x() = 0;
  virtual unsigned get_size_y() = 0;
  virtual EntitiesSystem *get_entities_system() = 0;
};
