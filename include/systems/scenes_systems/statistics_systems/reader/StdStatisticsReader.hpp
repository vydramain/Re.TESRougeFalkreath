//
// Created by vydra on 8/21/20.
//

#pragma once

#include <cstdio>

#include "IStatisticsReader.hpp"
#include "adds/log_systems/PseudoLogSystem.hpp"

class StdStatisticsReader : public IStatisticsReader {
 private:
  int char_in_string = 61;
  unsigned strings_count = 0;

  const char* file_name = nullptr;
  FILE* current_file = nullptr;

 public:
  explicit StdStatisticsReader(const char* input_file_name);
  ~StdStatisticsReader() override;

  unsigned get_strings_count() override;
  const char* get_string(unsigned input_index) override;
};
