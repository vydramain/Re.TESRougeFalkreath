//
// Created by vydra on 8/21/20.
//

#pragma once

#include "entities/location_entities/sentients_entities/Sentient.h"

class IStatisticsWriter {
 public:
  virtual ~IStatisticsWriter() = default;

  virtual void free_file() = 0;
  virtual void add_sentient_score(Sentient *input_sentient) = 0;
};
