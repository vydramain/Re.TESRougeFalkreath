//
// Created by vydra on 8/21/20.
//

#pragma once

#include <cmath>
#include <cstdio>

#include "adds/CCMech.h"
#include "adds/log_systems/PseudoLogSystem.hpp"
#include "entities/location_entities/sentients_entities/Sentient.h"
#include "systems/scenes_systems/statistics_systems/writer/IStatisticsWriter.hpp"

class StdStatisticsWriter : public IStatisticsWriter {
 private:
  int char_in_string = 61;
  const char* file_name = nullptr;
  FILE* current_file = nullptr;

  void set_cursor(Sentient* input_sentient);

 public:
  explicit StdStatisticsWriter(const char* input_file_name);
  ~StdStatisticsWriter() override;

  void free_file() override;
  void add_sentient_score(Sentient* input_sentient) override;
};
