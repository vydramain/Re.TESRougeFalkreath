//
// Created by vydra on 8/27/20.
//

#pragma once

#include "entities/location_entities/ambient_entities/LowerHatch.hpp"
#include "systems/scenes_systems/game_loop_systems/load/controls/ILControl.h"

class LControlLowerHatch : public ILControl {
 public:
  explicit LControlLowerHatch(LoadControlsEntitysData* input_data, EntitiesSystem* input_entities_system)
      : ILControl("LControlLowerHatch", input_data, input_entities_system) {}
  ~LControlLowerHatch() override = default;

  void execute() override {
    entities_system->put_ambient(new LowerHatch(data->get_x(), data->get_y()));
  }
};
