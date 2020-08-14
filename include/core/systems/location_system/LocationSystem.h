//
// Created by vydra on 15.07.2020.
//

#pragma once

#include "core/entities/location_enities/LocationsEntity.h"
#include "core/systems/location_system/ILocationSystem.h"
#include "core/systems/location_system/sub_systems/entities_system/ItemsSystem.h"
#include "core/systems/location_system/sub_systems/entities_system/LocationsEntitiesSystem.h"
#include "core/systems/location_system/sub_systems/entities_system/MagwehrsSystem.h"
#include "core/systems/location_system/sub_systems/entities_system/SentientsSystem.h"

class LocationSystem : public ILocationSystem {
 private:
  const unsigned size_x;
  const unsigned size_y;
  LocationsEntitiesSystem *entities;

 public:
  explicit LocationSystem(unsigned input_x, unsigned input_y, LocationsEntitiesSystem *input_entites);
  ~LocationSystem();

  unsigned get_size_x() const;
  unsigned get_size_y() const;
  LocationsEntitiesSystem *get_entities() const;
};
