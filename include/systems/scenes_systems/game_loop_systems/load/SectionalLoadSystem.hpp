//
// Created by vydra on 9/3/20.
//

#pragma once

#include "systems/scenes_systems/game_loop_systems/reader/map/MapSentientReader.hpp"
#include "adds/log_systems/PseudoLogSystem.hpp"
#include "systems/IControl.h"
#include "systems/scenes_systems//game_loop_systems/load/controls/LControlMap.h"
#include "systems/scenes_systems/game_loop_systems/load/IMapLoadSystem.h"
#include "systems/scenes_systems/game_loop_systems/load/sub_systems/auto_loot_system/AutoLootSystem.hpp"
#include "systems/scenes_systems/game_loop_systems/reader/map/MapAmbientReader.hpp"
#include "systems/scenes_systems/game_loop_systems/reader/map/MapItemReader.hpp"
#include "systems/scenes_systems/game_loop_systems/reader/map/MapTitleReader.hpp"
#include "systems/scenes_systems/game_loop_systems/world/sub_systems/map_systems/IMapSystem.hpp"
#include "systems/scenes_systems/game_loop_systems/world/sub_systems/map_systems/MapSystem.hpp"

class SectionalLoadSystem : IMapLoadSystem {
 private:
  std::string* map_name = nullptr;
  MapTitleReader *map_reader = nullptr;
  MapAmbientReader *ambient_reader = nullptr;
  MapSentientReader *sentient_reader = nullptr;
  MapItemReader *item_reader = nullptr;
  EntitiesSystem *entities_system = nullptr;

  bool check_files();
  void clear_fields();
  bool find_map();
  void complete_entities_ambient();
  void complete_entities_sentient();
  void complete_entities_item();
  void complete_entities_random_item();
  void create_entities_system();

 public:
  explicit SectionalLoadSystem(std::string* input_map_address);
  ~SectionalLoadSystem() override;

  void load_new_map() override;
  void load_old_map() override;

  std::string get_map_name() const override;
  unsigned get_location_size_x() const override;
  unsigned get_location_size_y() const override;
  EntitiesSystem *get_entities_system() const override;
  IMapSystem *get_map_system() const override;
};
