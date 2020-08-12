//
// Created by vydra on 15.07.2020.
//

#pragma once

#include "core/entities/location_enities/LocationsEntity.h"
#include "core/entities/location_enities/area_entities/Area.h"
#include "core/systems/location_system/sub_systems/entities_system/ItemsSystem.h"
#include "core/systems/location_system/sub_systems/entities_system/LocationsEntitiesSystem.h"
#include "core/systems/location_system/sub_systems/entities_system/MagwehrsSystem.h"
#include "core/systems/location_system/sub_systems/entities_system/SentientsSystem.h"

class LocationSystem {
 private:
  Area *area;
  LocationsEntitiesSystem *entities;

 public:
  explicit LocationSystem(Area *input_area, LocationsEntitiesSystem *input_entites);
  ~LocationSystem();

  Area *get_area() const;
  LocationsEntitiesSystem *get_entities() const;
};
