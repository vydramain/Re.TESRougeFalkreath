//
// Created by vydra on 9/2/20.
//

#pragma once

#include "systems_new/scenes_systems/game_loop_systems/world/sub_systems/map_systems/entities_system/IEntitiesSystem.hpp"

class IMapSystem {
  virtual ~IMapSystem() = default;

  virtual unsigned get_size_x() = 0;
  virtual unsigned get_size_y() = 0;

  virtual IEntitiesSystem get_entities() = 0;
};