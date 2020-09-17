//
// Created by vydra on 8/16/20.
//

#pragma once

#include "entities/location_entities/ambient_entities/SouthGate.h"
#include "systems/scenes_systems/game_loop_systems/load/controls/ILControl.h"
#include "systems/scenes_systems/game_loop_systems/world/sub_systems/map_systems/entities_system/EntitiesSystem.h"

class LControlSouthGate : public ILControl {
 public:
  explicit LControlSouthGate(LoadControlsEntitysData* input_data, EntitiesSystem* input_entities_system)
      : ILControl("LControlSouthGate", input_data, input_entities_system) {}
  ~LControlSouthGate() override = default;

  void execute() override {
    entities_system->put_ambient(new SouthGate(data->get_x(), data->get_y()));
  }
};
