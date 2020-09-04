//
// Created by vydra on 8/14/20.
//

#pragma once

#include <string>

#include "systems_new/scenes_systems/game_loop_systems/world/sub_systems/map_systems/entities_system/EntitiesSystem.h"

class IMapLoadSystem {
 public:
  virtual ~IMapLoadSystem() = default;

  virtual void load_map() = 0;

  virtual std::string get_map_name() const = 0;
  virtual unsigned get_location_size_x() const = 0;
  virtual unsigned get_location_size_y() const = 0;
  virtual EntitiesSystem *get_entities_system() const = 0;
};
