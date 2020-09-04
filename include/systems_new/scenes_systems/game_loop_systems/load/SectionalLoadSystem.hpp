//
// Created by vydra on 9/3/20.
//

#pragma once

#include "systems_new/scenes_systems/game_loop_systems/load/IMapLoadSystem.h"

class SectionalLoadSystem : ILoadSystem {
 private:
  MapReader *map_reader = nullptr;
  AmbientReader *ambient_reader = nullptr;
  ItemReader *item_reader = nullptr;
  IMapSystem *map_system = nullptr;

  bool check_file();
  void clear_fields();
  void create_entities_system();

 public:
  explicit SectionalLoadSystem(const char *input_map_name);
  ~SectionalLoadSystem() override;

  void load_map() override;

  EntitiesSystem *get_entities_system() const override;
  unsigned get_location_size_x() const override;
  unsigned get_location_size_y() const override;
};