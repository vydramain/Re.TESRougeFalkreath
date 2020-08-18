//
// Created by vydra on 8/18/20.
//

#pragma once

#include <cstdio>

#include "systems/score_systems/IScoreSystem.hpp"

class StdScoreSystem : public IScoreSystem {
 private:
  unsigned CHAR_IN_STRING = 61;

  FILE *score_file = nullptr;
  ILocationSystem *location_system = nullptr;

  unsigned score_count = 0;

 public:
  void set_location_system(ILocationSystem *input_location_system) override;

  explicit StdScoreSystem();
  ~StdScoreSystem() override;

  unsigned get_score_count() const override;
  const char *get_score_string(unsigned index) const override;

  void add_score() override;
};