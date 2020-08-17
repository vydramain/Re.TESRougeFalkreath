//
// Created by vydra on 8/14/20.
//

#pragma once

#include "systems/location_systems/sub_systems/entities_system/LocationsEntitiesSystem.h"

class ILoadSystem {
 public:
  virtual ~ILoadSystem() = default;

  virtual void load_map(const char *input_map_name) = 0;

  virtual LocationsEntitiesSystem *get_entities_system() const = 0;
  virtual unsigned get_location_size_x() const = 0;
  virtual unsigned get_location_size_y() const = 0;
};
