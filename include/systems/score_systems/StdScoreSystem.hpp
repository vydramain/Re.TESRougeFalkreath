//
// Created by vydra on 8/18/20.
//

#pragma once

#include <cstdio>

#include "systems/score_systems/IScoreSystem.hpp"

class StdScoreSystem : public IScoreSystem {
 private:
  int CHAR_IN_STRING = 61;

  FILE *score_file = nullptr;
  ILocationSystem *location_system = nullptr;

  unsigned records_count = 0;

 public:
  void set_location_system(ILocationSystem *input_location_system) override;

  explicit StdScoreSystem();
  ~StdScoreSystem() override;

  unsigned get_records_count() const override;
  const char *get_score_string(unsigned index) const override;

  void add_score() override;
  void free_file() override;
};