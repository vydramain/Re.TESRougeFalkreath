//
// Created by vydra on 8/21/20.
//

#pragma once

class IStatisticsReader {
 public:
  virtual ~IStatisticsReader() = default;

  virtual unsigned get_strings_count() = 0;
  virtual const char* get_string(unsigned input_index) = 0;
};
