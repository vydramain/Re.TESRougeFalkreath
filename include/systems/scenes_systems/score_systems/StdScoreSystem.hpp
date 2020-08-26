//
// Created by vydra on 8/18/20.
//

#pragma once

#include <cstdio>

#include "systems/rw_systems/reader_systems/score_readers/IScoreReader.hpp"
#include "systems/rw_systems/reader_systems/score_readers/StdScoreReader.hpp"
#include "systems/rw_systems/writer_systems/score_writers/IScoreWriter.hpp"
#include "systems/rw_systems/writer_systems/score_writers/StdScoreWriter.hpp"
#include "systems/scenes_systems/score_systems/IScoreSystem.hpp"

class StdScoreSystem : public IScoreSystem {
 private:
  IScoreReader *reader = nullptr;
  IScoreWriter *writer = nullptr;

  ILocationSystem *location_system = nullptr;

 public:
  void set_location_system(ILocationSystem *input_location_system) override;

  explicit StdScoreSystem();
  ~StdScoreSystem() override;

  unsigned get_records_count() const override;
  const char *get_score_string(unsigned input_index) const override;

  void add_score() override;
  void free_file() override;
};
