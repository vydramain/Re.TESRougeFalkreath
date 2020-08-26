//
// Created by vydra on 8/14/20.
//

#pragma once

#include "systems/scenes_systems/game_loop_systems/location_systems/sub_systems/entities_system/LocationsEntitiesSystem.h"

class ILoadSystem {
 public:
  virtual ~ILoadSystem() = default;

  virtual void load_map() = 0;

  virtual LocationsEntitiesSystem *get_entities_system() const = 0;
  virtual unsigned get_location_size_x() const = 0;
  virtual unsigned get_location_size_y() const = 0;
};
