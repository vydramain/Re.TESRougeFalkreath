//
// Created by vydra on 8/16/20.
//

#pragma once

#include "ILControl.h"
#include "entities/location_entities/ambient_entities/SouthGate.h"
#include "systems_new/scenes_systems/game_loop_systems/world/sub_systems/map_systems/entities_system/EntitiesSystem.h"

class LControlSouthGate : public ILControl {
 public:
  explicit LControlSouthGate(unsigned *input_x, unsigned *input_y, EntitiesSystem *input_entities_system)
      : ILControl("LControlSouthGate", input_x, input_y, input_entities_system) {}
  ~LControlSouthGate() override = default;

  void execute() override {
    entities_system->put_ambient(new SouthGate(*new_x, *new_y));
  }
};
