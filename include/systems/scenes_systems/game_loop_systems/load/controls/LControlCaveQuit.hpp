//
// Created by vydra on 8/27/20.
//

#pragma once

#include "ILControl.h"
#include "entities/location_entities/ambient_entities/CaveQuit.hpp"

class LControlCaveQuit : public ILControl {
 public:
  explicit LControlCaveQuit(unsigned *input_x, unsigned *input_y, EntitiesSystem *input_entities_system)
      : ILControl("LControlCaveQuit", input_x, input_y, input_entities_system) {}
  ~LControlCaveQuit() override = default;

  void execute() override {
    entities_system->put_ambient(new CaveQuit(*new_x, *new_y));
  }
};