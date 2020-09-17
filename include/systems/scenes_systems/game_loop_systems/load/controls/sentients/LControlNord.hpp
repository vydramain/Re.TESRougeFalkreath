//
// Created by vydra on 9/17/20.
//

#pragma once

#include "entities/location_entities/sentients_entities/humans/Nord.hpp"
#include "systems/scenes_systems/game_loop_systems/load/controls/ILControl.h"
#include "systems/scenes_systems/game_loop_systems/world/sub_systems/map_systems/entities_system/EntitiesSystem.h"

class LControlNord : public ILControl {
 public:
  explicit LControlNord(LoadControlsEntitysData* input_data, EntitiesSystem* input_entities_system)
      : ILControl("LControlNord", input_data, input_entities_system) {}
  ~LControlNord() override = default;

  void execute() override {
    entities_system->put_sentient(new Nord(data->get_nickname()->data(), data->get_x(), data->get_y()));
  }
};
