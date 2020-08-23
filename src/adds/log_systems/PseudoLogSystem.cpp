//
// Created by vydra on 8/21/20.
//

#include "adds/log_systems/PseudoLogSystem.hpp"

void PseudoLogSystem::log(const char *input_class_name, const char *input_log) {
  printf("[%s] - %s\n", input_class_name, input_log);
}

void PseudoLogSystem::log(const char *input_class_name, const char *input_first_log, const char *input_second_log) {
  printf("[%s] - %s %s\n", input_class_name, input_first_log, input_second_log);
}
