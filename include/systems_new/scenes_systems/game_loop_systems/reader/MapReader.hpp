//
// Created by vydra on 9/3/20.
//

#pragma once

#include <cstdio>
#include <string>

class MapReader {
 private:
  const char* file_name = nullptr;
  FILE* file = nullptr;

  char* map_name;
  unsigned size_x;
  unsigned size_y;

 public:
  explicit MapReader(const char* input_file_name);
  ~MapReader();

  const char* get_file_name();

  bool open();
  std::string get_map_name();
  unsigned int get_map_size_x();
  unsigned int get_map_size_y();
};
