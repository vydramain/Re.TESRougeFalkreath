//
// Created by vydra on 15.07.2020.
//

#ifndef INCLUDE_ECS_SYSTEMS_LOCATION_SYSTEM_LOCATION_H_
#define INCLUDE_ECS_SYSTEMS_LOCATION_SYSTEM_LOCATION_H_

#include "ecs/entities/Map.h"
#include "ecs/entities/creatures_entities/Creatures.h"
#include "ecs/entities/items_entities/Items.h"

class Location {
 private:
  const char *name;
  const unsigned size_x;
  const unsigned size_y;

  Map *current_area;
  Creatures *current_creatures;
  Items *current_items;

 public:
  explicit Location(const char *input_name, Map *input_area, Creatures *input_creatures, Items *input_items);
  ~Location();

  const char *get_name() const;
  unsigned int get_size_x() const;
  unsigned int get_size_y() const;
  Map *get_area() const;
  Creatures *get_creatures() const;
  Items *get_items() const;

  void set_name(const char *input_name);
};

#endif  // INCLUDE_ECS_SYSTEMS_LOCATION_SYSTEM_LOCATION_H_
