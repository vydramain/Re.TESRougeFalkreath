//
// Created by vydra on 7/31/20.
//

#ifndef INCLUDE_ECS_SYSTEMS_CONTROLS_SYSTEM_MENU_CONTROLS_MMCONTROLMAP_H_
#define INCLUDE_ECS_SYSTEMS_CONTROLS_SYSTEM_MENU_CONTROLS_MMCONTROLMAP_H_

#include <BearLibTerminal.h>

#include <map>

#include "./MMControlSelectDown.h"
#include "./MMControlSelectEmpty.h"
#include "./MMControlSelectEnter.h"
#include "./MMControlSelectExit.h"
#include "./MMControlSelectUp.h"

class MMControlMap {
 private:
  MMControlSelectExit *select_exit;
  MMControlSelectEmpty *select_empty;
  MMControlSelectEnter *select_enter;
  MMControlSelectDown *select_down;
  MMControlSelectUp *select_up;

  std::map<int, IControl *> mm_map;
  std::map<int, IControl *>::iterator mm_iterator;

 public:
  explicit MMControlMap(const unsigned input_count, unsigned *input_highlighted) {
    select_down = new MMControlSelectDown(input_count, input_highlighted);
    select_up = new MMControlSelectUp(input_count, input_highlighted);
    select_exit = new MMControlSelectExit();
    select_empty = new MMControlSelectEmpty();
    select_enter = new MMControlSelectEnter();

    mm_map[TK_CLOSE] = select_exit;
    mm_map[TK_ESCAPE] = select_exit;
    mm_map[TK_ENTER] = select_enter;
    mm_map[TK_UP] = select_up;
    mm_map[TK_DOWN] = select_down;
  }

  ~MMControlMap() {
    delete select_exit;
    delete select_empty;
    delete select_enter;
    delete select_down;
    delete select_up;
  }

  IControl *get_control(int input_key) {
    mm_iterator = mm_map.find(input_key);
    if (mm_iterator == mm_map.end()) {
      return select_empty;
    }
    return mm_iterator->second;
  }
};

#endif  // INCLUDE_ECS_SYSTEMS_CONTROLS_SYSTEM_MENU_CONTROLS_MMCONTROLMAP_H_
