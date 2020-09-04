//
// Created by vydra on 8/19/20.
//

#pragma once

#include <map>

#include "./BearLibTerminal.h"
#include "SControlEmpty.hpp"
#include "SControlSelectDelete.hpp"
#include "SControlSelectExit.hpp"
#include "SControlSelectLeft.hpp"
#include "SControlSelectRight.hpp"

class SControlMap {
 private:
  SControlEmpty *control_empty = nullptr;
  SControlSelectDelete *control_delete = nullptr;
  SControlSelectExit *control_exit = nullptr;
  SControlSelectLeft *control_left = nullptr;
  SControlSelectRight *control_right = nullptr;

  std::map<int, IControl *> sl_map;
  std::map<int, IControl *>::iterator sl_iterator;

 public:
  explicit SControlMap(IStatisticsSystem *input_score_system, StringsListData *input_score_list_data) {
    control_empty = new SControlEmpty();
    control_delete = new SControlSelectDelete(input_score_system, input_score_list_data);
    control_exit = new SControlSelectExit();
    control_left = new SControlSelectLeft(input_score_list_data);
    control_right = new SControlSelectRight(input_score_list_data);

    sl_map[TK_DELETE] = control_delete;
    sl_map[TK_ESCAPE] = control_exit;
    sl_map[TK_LEFT] = control_left;
    sl_map[TK_RIGHT] = control_right;
  }
  ~SControlMap() {
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
