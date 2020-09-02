//
// Created by vydra on 8/14/20.
//

#pragma once

#include "entities/location_entities/ambient_entities/Tree.h"
#include "systems/controls_systems/other_controls/load_controls/ILControl.h"
#include "systems_new/scenes_systems/game_loop_systems/world/sub_systems/map_systems/entities_system/EntitiesSystem.h"

class LControlTree : public ILControl {
 public:
  explicit LControlTree(unsigned *input_x, unsigned *input_y, EntitiesSystem *input_entities_system)
      : ILControl("LControlTree", input_x, input_y, input_entities_system) {}
  ~LControlTree() override = default;

  void execute() override {
    entities_system->put_ambient(new Tree(*new_x, *new_y));
  }
};
