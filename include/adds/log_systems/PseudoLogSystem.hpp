//
// Created by vydra on 8/21/20.
//

#pragma once

#include <cstdio>

class PseudoLogSystem {
 public:
  static void log(const char* input_class_name, const char* input_log);
  static void log(const char* input_class_name, const char* input_first_log, const char* input_second_log);
  static void log(const char* input_class_name, const char* input_first_log, const char* input_second_log, const char* input_third_log);
};
