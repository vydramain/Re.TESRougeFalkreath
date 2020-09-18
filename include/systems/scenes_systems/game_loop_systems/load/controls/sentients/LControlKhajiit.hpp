//
// Created by vydra on 9/17/20.
//

#pragma once

#include "entities/location_entities/sentients_entities/beastfolks/Khajiit.h"
#include "systems/scenes_systems/game_loop_systems/load/controls/ILControl.h"
#include "systems/scenes_systems/game_loop_systems/world/sub_systems/map_systems/entities_system/EntitiesSystem.h"

class LControlKhajiit : public ILControl {
 public:
  explicit LControlKhajiit(LoadControlsEntitysData* input_data, EntitiesSystem* input_entities_system)
      : ILControl("LControlKhajiit", input_data, input_entities_system) {}
  ~LControlKhajiit() override = default;

  void execute() override {
    entities_system->put_sentient(new Khajiit(data->get_nickname()->data(), data->get_x(), data->get_y()));
  }
};
