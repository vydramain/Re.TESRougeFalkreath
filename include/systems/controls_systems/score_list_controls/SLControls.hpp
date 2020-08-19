//
// Created by vydra on 8/19/20.
//

#pragma once

#include "./BearLibTerminal.h"
#include "systems/controls_systems/score_list_controls/SLControlMap.hpp"

class SLControls {
 private:
  SLControlMap *control_map;

 public:
  explicit SLControls(IScoreSystem *input_score_system, ScoreListData *input_score_list_data) {
    control_map = new SLControlMap(input_score_system, input_score_list_data);
  }

  ~SLControls() {
    delete control_map;
  }

  IControl *update() {
    auto key = terminal_read();
    return control_map->get_control(key);
  }
};
