//
// Created by vydra on 15.07.2020.
//

#pragma once

#include "core/entities/location_enities/LocationEntity.h"
#include "core/entities/location_enities/area_entities/Area.h"
#include "ecs/systems/location_system/Creatures.h"
#include "ecs/systems/location_system/Items.h"
#include "ecs/systems/location_system/Races.h"

class Location : public LocationEntity {
 private:
  Area *current_area;
  Races *current_races;
  Creatures *current_creatures;
  Items *current_items;

 public:
  explicit Location(const char *input_name, Area *input_area, Races *input_races, Creatures *input_creatures,
                    Items *input_items);
  ~Location();

  Area *get_area() const;
  Races *get_races() const;
  Creatures *get_creatures() const;
  Items *get_items() const;
};
