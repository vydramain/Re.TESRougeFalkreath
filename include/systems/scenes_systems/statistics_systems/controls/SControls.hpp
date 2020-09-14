//
// Created by vydra on 8/19/20.
//

#pragma once

#include "./BearLibTerminal.h"
#include "SControlMap.hpp"
#include "entities/render_entities/data/StringsListData.hpp"
#include "systems/scenes_systems/statistics_systems/IStatisticsSystem.hpp"

class SControls {
 private:
  SControlMap *control_map;

 public:
  explicit SControls(IStatisticsSystem *input_score_system, StringsListData *input_score_list_data) {
    control_map = new SControlMap(input_score_system, input_score_list_data);
  }

  ~SControls() {
    delete control_map;
  }

  IControl *update() {
    auto key = terminal_read();
    return control_map->get_control(key);
  }
};
