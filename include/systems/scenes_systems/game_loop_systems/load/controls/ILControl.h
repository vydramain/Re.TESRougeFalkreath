//
// Created by vydra on 8/14/20.
//

#pragma once

#include "systems/IControl.h"
#include "systems/scenes_systems/game_loop_systems/world/sub_systems/map_systems/entities_system/EntitiesSystem.h"
#include "systems/scenes_systems/game_loop_systems/load/controls/data/LoadControlsEntitysData.hpp"

class ILControl : public IControl {
 protected:
  LoadControlsEntitysData* data;
  EntitiesSystem *entities_system;

 public:
  explicit ILControl(const char *input_name, LoadControlsEntitysData* input_data,
                     EntitiesSystem *input_entities_system)
      : IControl(input_name), data(input_data), entities_system(input_entities_system) {}
  ~ILControl() override = default;

  void execute() override = 0;
};
