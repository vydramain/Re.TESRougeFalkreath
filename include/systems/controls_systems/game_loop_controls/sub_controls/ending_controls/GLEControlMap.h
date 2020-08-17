//
// Created by vydra on 7/31/20.
//

#pragma once

#include <map>

#include "./BearLibTerminal.h"
#include "systems/controls_systems/game_loop_controls/sub_controls/ending_controls/GLEControlSelectDown.h"
#include "systems/controls_systems/game_loop_controls/sub_controls/ending_controls/GLEControlSelectEmpty.h"
#include "systems/controls_systems/game_loop_controls/sub_controls/ending_controls/GLEControlSelectEnter.h"
#include "systems/controls_systems/game_loop_controls/sub_controls/ending_controls/GLEControlSelectExit.h"
#include "systems/controls_systems/game_loop_controls/sub_controls/ending_controls/GLEControlSelectUp.h"

class GLEControlMap {
 private:
  GLEControlSelectExit *select_exit = nullptr;
  GLEControlSelectEmpty *select_empty = nullptr;
  GLEControlSelectEnter *select_enter = nullptr;
  GLEControlSelectDown *select_down = nullptr;
  GLEControlSelectUp *select_up = nullptr;

  std::map<int, IControl *> gle_map;
  std::map<int, IControl *>::iterator gle_iterator;

 public:
  explicit GLEControlMap(LocationSystem *input_location_system, const unsigned input_count,
                         unsigned *input_highlighted) {
    printf("%s", "[MMControlMap] - Creating main menu controls\n");
    select_down = new GLEControlSelectDown(input_count, input_highlighted);
    select_up = new GLEControlSelectUp(input_count, input_highlighted);
    select_exit = new GLEControlSelectExit();
    select_empty = new GLEControlSelectEmpty();
    select_enter = new GLEControlSelectEnter(input_location_system);

    gle_map.insert(std::make_pair(TK_ESCAPE, select_exit));
    gle_map.insert(std::make_pair(TK_ENTER, select_enter));
    gle_map.insert(std::make_pair(TK_UP, select_up));
    gle_map.insert(std::make_pair(TK_DOWN, select_down));
  }

  ~GLEControlMap() {
    delete select_exit;
    delete select_empty;
    delete select_enter;
    delete select_down;
    delete select_up;
  }

  IControl *get_control(TERMINAL_API int input_key) {
    gle_iterator = gle_map.find(input_key);
    if (gle_iterator == gle_map.end()) {
      return select_empty;
    }
    return gle_iterator->second;
  }
};
