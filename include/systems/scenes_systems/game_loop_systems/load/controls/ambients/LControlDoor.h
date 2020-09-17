//
// Created by vydra on 8/16/20.
//

#pragma once

#include "entities/location_entities/ambient_entities/Door.h"
#include "systems/scenes_systems/game_loop_systems/load/controls/ILControl.h"
#include "systems/scenes_systems/game_loop_systems/world/sub_systems/map_systems/entities_system/EntitiesSystem.h"

class LControlDoor : public ILControl {
 public:
  explicit LControlDoor(LoadControlsEntitysData* input_data, EntitiesSystem* input_entities_system)
      : ILControl("LControlHedge", input_data, input_entities_system) {}
  ~LControlDoor() override = default;

  void execute() override {
    entities_system->put_ambient(new Door(data->get_x(), data->get_y()));
  }
};
