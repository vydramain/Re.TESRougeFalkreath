//
// Created by vydra on 8/27/20.
//

#pragma once

#include "entities/location_entities/ambient_entities/Glacier.hpp"
#include "systems/scenes_systems/game_loop_systems/load/controls/ILControl.h"

class LControlGlacier : public ILControl {
 public:
  explicit LControlGlacier(LoadControlsEntitysData* input_data, EntitiesSystem* input_entities_system)
      : ILControl("LControlGlacier", input_data, input_entities_system) {}
  ~LControlGlacier() override = default;

  void execute() override {
    entities_system->put_ambient(new Glacier(data->get_x(), data->get_y()));
  }
};
