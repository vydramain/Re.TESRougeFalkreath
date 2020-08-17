//
// Created by vydra on 8/14/20.
//

#pragma once

#include <cstdio>

#include "systems/load_systems/ILoadSystem.h"
#include "systems/controls_systems/load_controls/LControlMap.h"
#include "systems/location_systems/sub_systems/entities_system/LocationsEntitiesSystem.h"

class LoadSystem : public ILoadSystem {
 private:
  unsigned location_size_x;
  unsigned location_size_y;
  LocationsEntitiesSystem *entities_system;

  const char* file_name;
  FILE *map_file_stream;

  bool check_file();
  void clear_fields();
  void create_entities_system();

 public:
  explicit LoadSystem(const char *input_map_name);
  ~LoadSystem() override;

  void load_map() override;

  LocationsEntitiesSystem *get_entities_system() const override;
  unsigned get_location_size_x() const override;
  unsigned get_location_size_y() const override;
};
