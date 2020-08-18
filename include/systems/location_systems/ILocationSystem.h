//
// Created by vydra on 8/14/20.
//

#pragma once

#include "systems/location_systems/sub_systems/entities_system/LocationsEntitiesSystem.h"

class ILocationSystem {
 public:
  virtual ~ILocationSystem() = default;

  virtual unsigned get_size_x() const = 0;
  virtual unsigned get_size_y() const = 0;
  virtual LocationsEntitiesSystem *get_entities() = 0;
  virtual LocationsEntitiesSystem *get_entities() const = 0;
};