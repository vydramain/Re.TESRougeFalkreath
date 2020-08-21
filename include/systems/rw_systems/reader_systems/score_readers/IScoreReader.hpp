//
// Created by vydra on 8/21/20.
//

#pragma once

class IScoreReader {
 public:
  virtual ~IScoreReader() = default;

  virtual unsigned get_strings_count() = 0;
  virtual const char* get_string(unsigned input_index) = 0;
};