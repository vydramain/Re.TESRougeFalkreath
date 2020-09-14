//
// Created by vydra on 8/14/20.
//

#pragma once

#include "systems/scenes_systems/game_loop_systems/load/controls/ILControl.h"
#include "entities/location_entities/ambient_entities/Roadbrick.h"
#include "systems/scenes_systems/game_loop_systems/world/sub_systems/map_systems/entities_system/EntitiesSystem.h"

class LControlRoadbrick : public ILControl {
 public:
  explicit LControlRoadbrick(unsigned *input_x, unsigned *input_y, EntitiesSystem *input_entities_system)
      : ILControl("LControlRoadbrick", input_x, input_y, input_entities_system) {}
  ~LControlRoadbrick() override = default;

  void execute() override {
    entities_system->put_ambient(new Roadbrick(*new_x, *new_y));
  }
};
