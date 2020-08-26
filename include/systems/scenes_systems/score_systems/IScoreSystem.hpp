//
// Created by vydra on 8/18/20.
//

#pragma once

#include "systems/scenes_systems/game_loop_systems/location_systems/ILocationSystem.h"

class IScoreSystem {
 public:
  virtual ~IScoreSystem() = default;

  virtual void set_location_system(ILocationSystem* input_location_system) = 0;
  virtual unsigned get_records_count() const = 0;
  virtual const char* get_score_string(unsigned index) const = 0;

  virtual void add_score() = 0;
  virtual void free_file() = 0;
};
