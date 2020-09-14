//
// Created by vydra on 8/14/20.
//

#pragma once

#include "systems/IControl.h"
#include "systems/scenes_systems/game_loop_systems/world/sub_systems/map_systems/entities_system/EntitiesSystem.h"

class ILControl : public IControl {
 protected:
  unsigned *new_x;
  unsigned *new_y;
  EntitiesSystem *entities_system;

 public:
  explicit ILControl(const char *input_name, unsigned *input_x, unsigned *input_y,
                     EntitiesSystem *input_entities_system)
      : IControl(input_name), new_x(input_x), new_y(input_y), entities_system(input_entities_system) {}
  ~ILControl() override = default;

  void execute() override = 0;
};
