//
// Created by vydra on 9/3/20.
//

#pragma once

#include "adds/log_systems/PseudoLogSystem.hpp"
#include "systems_new/IControl.h"
#include "systems_new/scenes_systems//game_loop_systems/load/controls/LControlMap.h"
#include "systems_new/scenes_systems/game_loop_systems/load/IMapLoadSystem.h"
#include "systems_new/scenes_systems/game_loop_systems/reader/map/MapAmbientReader.hpp"
#include "systems_new/scenes_systems/game_loop_systems/reader/map/MapItemReader.hpp"
#include "systems_new/scenes_systems/game_loop_systems/reader/map/MapTitleReader.hpp"
#include "systems_new/scenes_systems/game_loop_systems/world/sub_systems/map_systems/IMapSystem.hpp"
#include "systems_new/scenes_systems/game_loop_systems/world/sub_systems/map_systems/MapSystem.hpp"

class SectionalLoadSystem : IMapLoadSystem {
 private:
  MapTitleReader *map_reader = nullptr;
  MapAmbientReader *ambient_reader = nullptr;
  MapItemReader *item_reader = nullptr;
  EntitiesSystem *entities_system = nullptr;

  bool check_file();
  void clear_fields();
  void complete_entities_ambient();
  void complete_entities_item();
  void complete_entities_random_item();
  void create_entities_system();

 public:
  explicit SectionalLoadSystem(std::string input_map_address);
  ~SectionalLoadSystem() override;

  void load_map() override;

  std::string get_map_name() const override;
  unsigned get_location_size_x() const override;
  unsigned get_location_size_y() const override;
  EntitiesSystem *get_entities_system() const override;
  IMapSystem *get_map_system() const override;
};
