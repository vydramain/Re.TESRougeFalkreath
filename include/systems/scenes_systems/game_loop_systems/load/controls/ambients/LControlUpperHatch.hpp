//
// Created by vydra on 8/26/20.
//

#pragma once

#include "entities/location_entities/ambient_entities/UpperHatch.hpp"
#include "systems/scenes_systems/game_loop_systems/load/controls/ILControl.h"

class LControlUpperHatch : public ILControl {
 public:
  explicit LControlUpperHatch(LoadControlsEntitysData* input_data, EntitiesSystem* input_entities_system)
      : ILControl("LControlUpperHatch", input_data, input_entities_system) {}
  ~LControlUpperHatch() override = default;

  void execute() override {
    entities_system->put_ambient(new UpperHatch(data->get_x(), data->get_y()));
  }
};
