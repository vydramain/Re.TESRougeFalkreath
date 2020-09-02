//
// Created by vydra on 8/16/20.
//

#pragma once

#include "entities/location_entities/ambient_entities/Door.h"
#include "systems/controls_systems/other_controls/load_controls/ILControl.h"
#include "systems_new/scenes_systems/game_loop_systems/world/sub_systems/map_systems/entities_system/EntitiesSystem.h"

class LControlDoor : public ILControl {
 public:
  explicit LControlDoor(unsigned *input_x, unsigned *input_y, EntitiesSystem *input_entities_system)
      : ILControl("LControlHedge", input_x, input_y, input_entities_system) {}
  ~LControlDoor() override = default;

  void execute() override {
    entities_system->put_ambient(new Door(*new_x, *new_y));
  }
};
