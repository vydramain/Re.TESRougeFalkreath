//
// Created by vydra on 8/21/20.
//

#pragma once

#include <cstdio>

#include "IScoreWriter.hpp"
#include "entities/location_entities/sentients_entities/Sentient.h"
#include "systems/pseudo_log_systems/PseudoLogSystem.hpp"

class StdScoreWriter : public IScoreWriter {
 private:
  const char* file_name = nullptr;
  FILE* current_file = nullptr;

 public:
  explicit StdScoreWriter(const char* input_file_name);
  ~StdScoreWriter() override;

  void free_file() override;
  void add_sentient_score(Sentient *input_sentient) override;
};
