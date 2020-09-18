//
// Created by vydra on 8/14/20.
//

#pragma once

#include "entities/location_entities/ambient_entities/Cobblestone.h"
#include "systems/scenes_systems/game_loop_systems/load/controls/ILControl.h"
#include "systems/scenes_systems/game_loop_systems/world/sub_systems/map_systems/entities_system/EntitiesSystem.h"

class LControlCobblestone : public ILControl {
 public:
  explicit LControlCobblestone(LoadControlsEntitysData* input_data, EntitiesSystem* input_entities_system)
      : ILControl("LControlCobblestone", input_data, input_entities_system) {}
  ~LControlCobblestone() override = default;

  void execute() override {
    entities_system->put_ambient(new Cobblestone(data->get_x(), data->get_y()));
  }
};
