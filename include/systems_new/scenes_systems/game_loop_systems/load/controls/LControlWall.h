//
// Created by vydra on 8/14/20.
//

#pragma once

#include "ILControl.h"
#include "entities/location_entities/ambient_entities/Wall.h"
#include "systems_new/scenes_systems/game_loop_systems/world/sub_systems/map_systems/entities_system/EntitiesSystem.h"

class LControlWall : public ILControl {
 public:
  explicit LControlWall(unsigned *input_x, unsigned *input_y, EntitiesSystem *input_entities_system)
      : ILControl("LControlWall", input_x, input_y, input_entities_system) {}
  ~LControlWall() override = default;

  void execute() override {
    entities_system->put_ambient(new Wall(*new_x, *new_y));
  }
};
