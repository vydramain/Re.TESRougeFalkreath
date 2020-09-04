//
// Created by vydra on 8/21/20.
//

#pragma once

#include <cstdio>

#include "adds/log_systems/PseudoLogSystem.hpp"
#include "entities/location_entities/sentients_entities/Sentient.h"
#include "systems/scenes_systems/statistics_systems/writer/IStatisticsWriter.hpp"

class StdStatisticsWriter : public IStatisticsWriter {
 private:
  const char* file_name = nullptr;
  FILE* current_file = nullptr;

 public:
  explicit StdStatisticsWriter(const char* input_file_name);
  ~StdStatisticsWriter() override;

  void free_file() override;
  void add_sentient_score(Sentient* input_sentient) override;
};
