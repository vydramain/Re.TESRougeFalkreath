//
// Created by vydra on 15.07.2020.
//

#pragma once

#include "ecs/entities/location_enities/Area.h"
#include "ecs/systems/location_system/Creatures.h"
#include "ecs/systems/location_system/Items.h"
#include "ecs/systems/location_system/Races.h"

class Location {
 private:
  const char *name;
  const unsigned size_x;
  const unsigned size_y;

  Area *current_area;
  Races *current_races;
  Creatures *current_creatures;
  Items *current_items;

 public:
  explicit Location(const char *input_name, Area *input_area, Races *input_races, Creatures *input_creatures,
                    Items *input_items);
  ~Location();

  const char *get_name() const;
  unsigned int get_size_x() const;
  unsigned int get_size_y() const;
  Area *get_area() const;
  Races *get_races() const;
  Creatures *get_creatures() const;
  Items *get_items() const;

  void set_name(const char *input_name);
};
