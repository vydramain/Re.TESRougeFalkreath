//
// Created by vydra on 8/21/20.
//

#pragma once

#include <cstdio>

#include "systems/pseudo_log_systems/PseudoLogSystem.hpp"
#include "systems/rw_systems/reader_systems/score_readers/IScoreReader.hpp"

class StdScoreReader : public IScoreReader {
 private:
  int char_in_string = 61;
  unsigned strings_count = 0;

  const char* file_name = nullptr;
  FILE* current_file = nullptr;

 public:
  explicit StdScoreReader(const char* input_file_name);
  ~StdScoreReader() override;

  unsigned get_strings_count() override;
  const char* get_string(unsigned input_index) override;
};