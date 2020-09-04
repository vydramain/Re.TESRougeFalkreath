//
// Created by vydra on 8/14/20.
//

#pragma once

#include "ILControl.h"
#include "entities/location_entities/ambient_entities/Water.h"
#include "systems_new/scenes_systems/game_loop_systems/world/sub_systems/map_systems/entities_system/EntitiesSystem.h"

class LControlWater : public ILControl {
 public:
  explicit LControlWater(unsigned *input_x, unsigned *input_y, EntitiesSystem *input_entities_system)
      : ILControl("LControlWater", input_x, input_y, input_entities_system) {}
  ~LControlWater() override = default;

  void execute() override {
    entities_system->put_ambient(new Water(*new_x, *new_y));
  }
};
