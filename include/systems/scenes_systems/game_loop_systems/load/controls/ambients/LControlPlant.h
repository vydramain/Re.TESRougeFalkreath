//
// Created by vydra on 8/14/20.
//

#pragma once

#include "entities/location_entities/ambient_entities/Plant.h"
#include "systems/scenes_systems/game_loop_systems/load/controls/ILControl.h"
#include "systems/scenes_systems/game_loop_systems/world/sub_systems/map_systems/entities_system/EntitiesSystem.h"

class LControlPlant : public ILControl {
 public:
  explicit LControlPlant(LoadControlsEntitysData* input_data, EntitiesSystem* input_entities_system)
      : ILControl("LControlPlant", input_data, input_entities_system) {}
  ~LControlPlant() override = default;

  void execute() override {
    entities_system->put_ambient(new Plant(data->get_x(), data->get_y()));
  }
};
