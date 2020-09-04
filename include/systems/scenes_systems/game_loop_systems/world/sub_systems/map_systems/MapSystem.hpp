//
// Created by vydra on 9/2/20.
//

#pragma once

#include "systems/scenes_systems/game_loop_systems/world/sub_systems/map_systems/IMapSystem.hpp"
#include "systems/scenes_systems/game_loop_systems/world/sub_systems/map_systems/entities_system/EntitiesSystem.h"

class MapSystem : public IMapSystem {
 private:
  std::string name;
  unsigned size_x;
  unsigned size_y;
  EntitiesSystem *entities_system;

 public:
  explicit MapSystem(std::string input_name, unsigned input_size_x, unsigned input_size_y,
                     EntitiesSystem *input_entities_system);
  ~MapSystem() override;

  std::string get_name() override;
  unsigned get_size_x() override;
  unsigned get_size_y() override;
  EntitiesSystem *get_entities_system() override;
};
