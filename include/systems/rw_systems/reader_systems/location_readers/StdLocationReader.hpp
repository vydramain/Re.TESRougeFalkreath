//
// Created by vydra on 8/23/20.
//

#pragma once

#include <cstdio>

#include "systems/rw_systems/reader_systems/location_readers/ILocationReader.hpp"

class StdLocationReader : public ILocationReader {
 private:
  const char* file_name = nullptr;
  FILE* file = nullptr;

  unsigned int x_location_size = 0;
  unsigned int y_location_size = 0;

 public:
  explicit StdLocationReader(const char* input_file_name);
  ~StdLocationReader() override;

  const char* get_file_name() override;

  bool open() override;
  unsigned int get_x_location_size() override;
  unsigned int get_y_location_size() override;

  bool has_next() override;
  unsigned int get_char() override;
};
