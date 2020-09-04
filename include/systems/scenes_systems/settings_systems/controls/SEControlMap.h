//
// Created by vydra on 7/31/20.
//

#pragma once

#include <map>

#include "./BearLibTerminal.h"
#include "adds/log_systems/PseudoLogSystem.hpp"
#include "systems/IControl.h"
#include "entities/ParameterQueryData.hpp"
#include "systems/scenes_systems/settings_systems/controls/SEControlSelectDown.h"
#include "systems/scenes_systems/settings_systems/controls/SEControlSelectEmpty.h"
#include "systems/scenes_systems/settings_systems/controls/SEControlSelectEnter.h"
#include "systems/scenes_systems/settings_systems/controls/SEControlSelectExit.h"
#include "systems/scenes_systems/settings_systems/controls/SEControlSelectUp.h"

class SEControlMap {
 private:
  SEControlSelectExit *exit = nullptr;
  SEControlSelectEmpty *empty = nullptr;
  SEControlSelectEnter *enter = nullptr;
  SEControlSelectDown *down = nullptr;
  SEControlSelectUp *up = nullptr;

  std::map<int, IControl *> s_map;
  std::map<int, IControl *>::iterator s_iterator;

 public:
  explicit SEControlMap(ParameterQueryData *input_settings_data) {
    PseudoLogSystem::log("SEControlMap", "Create settings controls");
    down = new SEControlSelectDown(input_settings_data);
    up = new SEControlSelectUp(input_settings_data);
    exit = new SEControlSelectExit();
    empty = new SEControlSelectEmpty();
    enter = new SEControlSelectEnter();

    s_map.insert(std::make_pair(TK_CLOSE, exit));
    s_map.insert(std::make_pair(TK_ESCAPE, exit));
    s_map.insert(std::make_pair(TK_ENTER, enter));
    s_map.insert(std::make_pair(TK_UP, up));
    s_map.insert(std::make_pair(TK_DOWN, down));
  }

  ~SEControlMap() {
    PseudoLogSystem::log("SEControlMap", "Delete settings controls");
    delete exit;
    delete empty;
    delete enter;
    delete down;
    delete up;
  }

  IControl *get_control(TERMINAL_API int input_key) {
    s_iterator = s_map.find(input_key);
    if (s_iterator == s_map.end()) {
      return empty;
    }
    return s_iterator->second;
  }
};
