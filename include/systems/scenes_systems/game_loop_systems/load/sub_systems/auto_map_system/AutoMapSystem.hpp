//
// Created by vydra on 9/5/20.
//

#pragma once

#include <string>

#include "entities/location_entities/ambient_entities/CaveQuit.hpp"
#include "entities/location_entities/ambient_entities/Cobblestone.h"
#include "entities/location_entities/ambient_entities/LowerHatch.hpp"
#include "entities/location_entities/items_entities/Coin.h"
#include "systems/scenes_systems/game_loop_systems/load/sub_systems/auto_loot_system/AutoLootSystem.hpp"
#include "systems/scenes_systems/game_loop_systems/world/sub_systems/map_systems/IMapSystem.hpp"
#include "systems/scenes_systems/game_loop_systems/world/sub_systems/map_systems/entities_system/EntitiesSystem.h"

class AutoMapSystem {
 private:
  unsigned large_room_size_x = 40;
  unsigned large_room_size_y = 15;
  unsigned middle_room_size_x = 20;
  unsigned middle_room_size_y = 10;
  unsigned small_room_size_x = 10;
  unsigned small_room_size_y = 10;

  unsigned corridor_size_length = 5;
  unsigned corridor_size_width = 3;


  std::string map_name;
  unsigned size_x = 0;
  unsigned size_y = 0;
  EntitiesSystem *entities_system = nullptr;

  void generate_small_room(unsigned input_x, unsigned input_y);
  void generate_middle_room(unsigned input_x, unsigned input_y);
  void generate_large_room(unsigned input_x, unsigned input_y);

  void generate_corridors_horizontal(unsigned input_x, unsigned input_y);
  void generate_corridors_vertical(unsigned input_x, unsigned input_y);

  void clear_entrance_to_room(unsigned input_x, unsigned input_y, unsigned last_random);
  void clear_entrance_to_corridor_horizon(unsigned input_x, unsigned input_y);
  void clear_entrance_to_corridor_vertical(unsigned input_x, unsigned input_y);

  void generate_exit(unsigned input_x, unsigned input_y);
  void generate_entrance(unsigned input_x, unsigned input_y);
  void generate_coins(unsigned input_x, unsigned input_y);

  void generate_random_room(unsigned &input_x, unsigned &input_y, unsigned input_random, unsigned last_random = 0);
  unsigned int generate_random_corridor(unsigned int &input_x, unsigned int &input_y, unsigned int input_random);

 public:
  explicit AutoMapSystem(std::string input_map_name);
  ~AutoMapSystem();

  IMapSystem *generate_location();
};