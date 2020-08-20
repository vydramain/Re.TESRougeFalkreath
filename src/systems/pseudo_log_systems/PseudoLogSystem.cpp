//
// Created by vydra on 8/21/20.
//

#include "systems/pseudo_log_systems/PseudoLogSystem.hpp"

void PseudoLogSystem::log(const char *input_class_name, const char *input_log) {
  printf("[%s] - %s\n", input_class_name, input_log);
}
