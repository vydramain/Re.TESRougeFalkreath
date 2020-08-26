//
// Created by vydra on 8/27/20.
//

#pragma once

#include "entities/location_entities/ambient_entities/CaveQuit.hpp"
#include "systems/controls_systems/other_controls/load_controls/ILControl.h"

class LControlCaveQuit : public ILControl {
 public:
  explicit LControlCaveQuit(unsigned *input_x, unsigned *input_y, LocationsEntitiesSystem *input_entities_system)
      : ILControl("LControlCaveQuit", input_x, input_y, input_entities_system) {}
  ~LControlCaveQuit() override = default;

  void execute() override {
    entities_system->put_ambient(new CaveQuit(*new_x, *new_y));
  }
};