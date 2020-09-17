//
// Created by vydra on 9/4/20.
//

#pragma once

#include <cstdio>
#include <string>

class MapReader {
 protected:
  std::string* file_name;
  FILE* file = nullptr;

 public:
  explicit MapReader(std::string* input_file_name);
  virtual ~MapReader();

  std::string* get_file_name();

  virtual bool open() = 0;
  bool is_file();
};
