//
// Created by vydra on 8/24/20.
//

#pragma once

#include "entities/location_entities/ambient_entities/EastGate.hpp"
#include "systems/scenes_systems/game_loop_systems/load/controls/ILControl.h"
#include "systems/scenes_systems/game_loop_systems/world/sub_systems/map_systems/entities_system/EntitiesSystem.h"

class LControlEastGate : public ILControl {
 public:
  explicit LControlEastGate(LoadControlsEntitysData* input_data, EntitiesSystem* input_entities_system)
      : ILControl("LControlEastGate", input_data, input_entities_system) {}
  ~LControlEastGate() override = default;

  void execute() override {
    entities_system->put_ambient(new EastGate(data->get_x(), data->get_y()));
  }
};
