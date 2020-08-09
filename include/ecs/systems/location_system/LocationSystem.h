//
// Created by vydra on 15.07.2020.
//

#pragma once

#include "core/entities/location_enities/LocationsEntity.h"
#include "core/entities/location_enities/area_entities/Area.h"
#include "ecs/systems/location_system/sub_systems/entities_system/ItemsSystem.h"
#include "ecs/systems/location_system/sub_systems/entities_system/MagwehrsSystem.h"
#include "ecs/systems/location_system/sub_systems/entities_system/SentientsSystem.h"

class LocationSystem {
 private:
  Area *current_area;
  SentientsSystem *current_races;
  MagwehrsSystem *current_creatures;
  ItemsSystem *current_items;

 public:
  explicit LocationSystem(const char *input_name, Area *input_area, SentientsSystem *input_races,
                          MagwehrsSystem *input_creatures, ItemsSystem *input_items);
  ~LocationSystem();

  Area *get_area() const;
  SentientsSystem *get_races() const;
  MagwehrsSystem *get_creatures() const;
  ItemsSystem *get_items() const;
};
