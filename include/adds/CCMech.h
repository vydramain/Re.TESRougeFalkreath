//
// Created by vydra on 8/10/20.
//

#pragma once

#include <string>
#include <vector>

class CCMech {
 public:
  static int strpos(const char *s, const char *c, int n = 0);
  static std::vector<std::string *> split(std::string *input_text);
};
