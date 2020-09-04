//
// Created by vydra on 9/3/20.
//

#pragma once

#include <cstdio>
#include <string>

class AmbientReader {
 private:
  const char* file_name = nullptr;
  FILE* file = nullptr;

 public:
  explicit AmbientReader(const char* input_file_name);
  ~AmbientReader();

  const char* get_file_name();

  bool open();
  bool has_next();
  unsigned int get_char();
};
