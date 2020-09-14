//
// Created by vydra on 8/10/20.
//

#pragma once

#include <cstring>
#include <string>
#include <vector>

#define SET "+-*"

class CCMech {
 public:
  static int strpos(const char *s, const char *c, int n = 0);
  static std::vector<std::string *> split(std::string *input_text);
  static int char_to_int(char c);
};
