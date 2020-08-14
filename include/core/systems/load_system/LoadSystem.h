//
// Created by vydra on 8/14/20.
//

#pragma once

#include <cstdio>

#include "core/systems/controls_system/load_control/LControlMap.h"
#include "core/systems/load_system/ILoadSystem.h"
#include "core/systems/location_system/sub_systems/entities_system/LocationsEntitiesSystem.h"

class LoadSystem : public ILoadSystem {
 private:
  unsigned location_size_x;
  unsigned location_size_y;
  LocationsEntitiesSystem *entities_system;
  FILE *map_file_stream;

  bool check_file();
  void clear_fields();
  void create_entities_system();

 public:
  explicit LoadSystem();
  ~LoadSystem() override;

  void load_map(const char *input_map_name) override;

  LocationsEntitiesSystem *get_entities_system() const override;
  unsigned get_location_size_x() const override;
  unsigned get_location_size_y() const override;
};