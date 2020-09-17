//
// Created by vydra on 8/27/20.
//

#pragma once

#include "entities/location_entities/ambient_entities/Throne.hpp"
#include "systems/scenes_systems/game_loop_systems/load/controls/ILControl.h"

class LControlThrone : public ILControl {
 public:
  explicit LControlThrone(LoadControlsEntitysData* input_data, EntitiesSystem* input_entities_system)
      : ILControl("LControlThrone", input_data, input_entities_system) {}
  ~LControlThrone() override = default;

  void execute() override {
    entities_system->put_ambient(new Throne(data->get_x(), data->get_y()));
  }
};