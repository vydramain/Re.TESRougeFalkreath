//
// Created by vydra on 9/2/20.
//

#pragma once

#include "systems_new/scenes_systems/game_loop_systems/world/sub_systems/map_systems/IMapSystem.hpp"

class MapSystem : public IMapSystem {
 private:
  unsigned size_x;
  unsigned size_y;
  IEntitiesSystem *entities_system;

 public:
  explicit MapSystem(unsigned input_size_x, unsigned input_size_y, IEntitiesSystem *input_entities_system);
  ~MapSystem() override;

  unsigned get_size_x() override;
  unsigned get_size_y() override;
  IEntitiesSystem *get_entities_system() override;
};