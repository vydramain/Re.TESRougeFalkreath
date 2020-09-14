//
// Created by vydra on 7/31/20.
//

#pragma once

#include <map>

#include "./BearLibTerminal.h"
#include "adds/log_systems/PseudoLogSystem.hpp"
#include "systems/IControl.h"
#include "systems/scenes_systems/main_menu_systems/controls/MMControlSelectDown.h"
#include "systems/scenes_systems/main_menu_systems/controls/MMControlSelectEmpty.h"
#include "systems/scenes_systems/main_menu_systems/controls/MMControlSelectEnter.h"
#include "systems/scenes_systems/main_menu_systems/controls/MMControlSelectExit.h"
#include "systems/scenes_systems/main_menu_systems/controls/MMControlSelectUp.h"

class MMControlMap {
 private:
  MMControlSelectExit *exit = nullptr;
  MMControlSelectEmpty *empty = nullptr;
  MMControlSelectEnter *enter = nullptr;
  MMControlSelectDown *down = nullptr;
  MMControlSelectUp *up = nullptr;

  std::map<int, IControl *> mm_map;
  std::map<int, IControl *>::iterator mm_iterator;

 public:
  explicit MMControlMap(ParameterQueryData *input_menu_data) {
    PseudoLogSystem::log("MMControlMap", "Create main menu controls");
    down = new MMControlSelectDown(input_menu_data);
    up = new MMControlSelectUp(input_menu_data);
    exit = new MMControlSelectExit();
    empty = new MMControlSelectEmpty();
    enter = new MMControlSelectEnter();

    mm_map.insert(std::make_pair(TK_CLOSE, exit));
    mm_map.insert(std::make_pair(TK_ESCAPE, exit));
    mm_map.insert(std::make_pair(TK_ENTER, enter));
    mm_map.insert(std::make_pair(TK_UP, up));
    mm_map.insert(std::make_pair(TK_DOWN, down));
  }

  ~MMControlMap() {
    PseudoLogSystem::log("MMControlMap", "Delete main menu controls");
    delete exit;
    delete empty;
    delete enter;
    delete down;
    delete up;
  }

  IControl *get_control(TERMINAL_API int input_key) {
    mm_iterator = mm_map.find(input_key);
    if (mm_iterator == mm_map.end()) {
      return empty;
    }
    return mm_iterator->second;
  }
};
