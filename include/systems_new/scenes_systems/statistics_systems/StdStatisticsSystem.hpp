//
// Created by vydra on 8/18/20.
//

#pragma once

#include <cstdio>

#include "IStatisticsSystem.hpp"
#include "systems_new/scenes_systems/statistics_systems/reader/IStatisticsReader.hpp"
#include "systems_new/scenes_systems/statistics_systems/reader/StdStatisticsReader.hpp"
#include "systems_new/scenes_systems/statistics_systems/writer/IStatisticsWriter.hpp"
#include "systems_new/scenes_systems/statistics_systems/writer/StdStatisticsWriter.hpp"

class StdStatisticsSystem : public IStatisticsSystem {
 private:
  IStatisticsReader *reader = nullptr;
  IStatisticsWriter *writer = nullptr;

  ILocationSystem *location_system = nullptr;

 public:
  void set_location_system(ILocationSystem *input_location_system) override;

  explicit StdStatisticsSystem();
  ~StdStatisticsSystem() override;

  unsigned get_records_count() const override;
  const char *get_score_string(unsigned input_index) const override;

  void add_score() override;
  void free_file() override;
};
