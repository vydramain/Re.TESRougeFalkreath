//
// Created by vydra on 8/18/20.
//

#pragma once

#include "systems/location_systems/ILocationSystem.h"

class IScoreSystem {
 public:
  virtual ~IScoreSystem();

  void set_location_data(ILocationSystem *input_location_system);
  unsigned get_score_count() const;
  const char* get_score_string() const;

  void add_score();
  void read_score();
};