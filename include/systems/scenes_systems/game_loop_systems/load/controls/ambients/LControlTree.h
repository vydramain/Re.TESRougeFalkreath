//
// Created by vydra on 8/14/20.
//

#pragma once

#include "entities/location_entities/ambient_entities/Tree.h"
#include "systems/scenes_systems/game_loop_systems/load/controls/ILControl.h"
#include "systems/scenes_systems/game_loop_systems/world/sub_systems/map_systems/entities_system/EntitiesSystem.h"

class LControlTree : public ILControl {
 public:
  explicit LControlTree(LoadControlsEntitysData* input_data, EntitiesSystem* input_entities_system)
      : ILControl("LControlTree", input_data, input_entities_system) {}
  ~LControlTree() override = default;

  void execute() override {
    entities_system->put_ambient(new Tree(data->get_x(), data->get_y()));
  }
};
