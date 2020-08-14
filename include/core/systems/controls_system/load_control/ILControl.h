//
// Created by vydra on 8/14/20.
//

#pragma once

#include "core/systems/controls_system/IControl.h"
#include "core/systems/location_system/sub_systems/entities_system/LocationsEntitiesSystem.h"

class ILControl : public IControl {
 protected:
  unsigned *new_x;
  unsigned *new_y;
  LocationsEntitiesSystem *entities_system;

 public:
  explicit ILControl(const char *input_name, unsigned *input_x, unsigned *input_y,
                     LocationsEntitiesSystem *input_entities_system)
      : IControl(input_name), new_x(input_x), new_y(input_y), entities_system(input_entities_system) {}
  ~ILControl() override = default;

  void execute() override = 0;
};
