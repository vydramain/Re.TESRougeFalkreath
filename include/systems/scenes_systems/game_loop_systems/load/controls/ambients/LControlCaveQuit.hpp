//
// Created by vydra on 8/27/20.
//

#pragma once

#include "entities/location_entities/ambient_entities/CaveQuit.hpp"
#include "systems/scenes_systems/game_loop_systems/load/controls/ILControl.h"

class LControlCaveQuit : public ILControl {
 public:
  explicit LControlCaveQuit(LoadControlsEntitysData* input_data, EntitiesSystem* input_entities_system)
      : ILControl("LControlCaveQuit", input_data, input_entities_system) {}
  ~LControlCaveQuit() override = default;

  void execute() override {
    entities_system->put_ambient(new CaveQuit(data->get_x(), data->get_y()));
  }
};
