//
// Created by vydra on 8/19/20.
//

#pragma once

#include <map>

#include "./BearLibTerminal.h"
#include "systems/controls_systems/score_list_controls/SLControlEmpty.hpp"
#include "systems/controls_systems/score_list_controls/SLControlSelectDelete.hpp"
#include "systems/controls_systems/score_list_controls/SLControlSelectExit.hpp"
#include "systems/controls_systems/score_list_controls/SLControlSelectLeft.hpp"
#include "systems/controls_systems/score_list_controls/SLControlSelectRight.hpp"

class SLControlMap {
 private:
  SLControlEmpty *control_empty = nullptr;
  SLControlSelectDelete *control_delete = nullptr;
  SLControlSelectExit *control_exit = nullptr;
  SLControlSelectLeft *control_left = nullptr;
  SLControlSelectRight *control_right = nullptr;

  std::map<int, IControl *> sl_map;
  std::map<int, IControl *>::iterator sl_iterator;

 public:
  explicit SLControlMap(IScoreSystem *input_score_system, ScoreListData *input_score_list_data) {
    control_empty = new SLControlEmpty();
    control_delete = new SLControlSelectDelete(input_score_system, input_score_list_data);
    control_exit = new SLControlSelectExit();
    control_left = new SLControlSelectLeft(input_score_list_data);
    control_right = new SLControlSelectRight(input_score_list_data);

    sl_map[TK_DELETE] = control_delete;
    sl_map[TK_ESCAPE] = control_exit;
    sl_map[TK_LEFT] = control_left;
    sl_map[TK_RIGHT] = control_right;
  }
  ~SLControlMap() {
    delete control_delete;
    delete control_exit;
    delete control_left;
    delete control_right;
  }

  IControl *get_control(TERMINAL_API int input_key) {
    sl_iterator = sl_map.find(input_key);
    if (sl_iterator == sl_map.end()) {
      return control_empty;
    }
    return sl_iterator->second;
  }
};
