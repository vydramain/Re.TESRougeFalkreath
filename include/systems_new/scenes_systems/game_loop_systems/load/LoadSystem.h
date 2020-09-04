//
// Created by vydra on 8/14/20.
//

#pragma once

#include <cstdio>

#include "IMapLoadSystem.h"
#include "adds/log_systems/PseudoLogSystem.hpp"
#include "systems/controls_systems/other_controls/load_controls/LControlMap.h"
#include "systems/rw_systems/reader_systems/location_readers/ILocationReader.hpp"
#include "systems/rw_systems/reader_systems/location_readers/StdLocationReader.hpp"
#include "systems_new/scenes_systems/game_loop_systems/world/sub_systems/map_systems/entities_system/EntitiesSystem.h"

class LoadSystem : public IMapLoadSystem {
 private:
  ILocationReader *reader = nullptr;
  EntitiesSystem *entities_system = nullptr;

  bool check_file();
  void clear_fields();
  void create_entities_system();

 public:
  explicit LoadSystem(const char *input_map_name);
  ~LoadSystem() override;

  void load_map() override;

  std::string get_map_name() const;
  EntitiesSystem *get_entities_system() const override;
  unsigned get_location_size_x() const override;
  unsigned get_location_size_y() const override;
};
