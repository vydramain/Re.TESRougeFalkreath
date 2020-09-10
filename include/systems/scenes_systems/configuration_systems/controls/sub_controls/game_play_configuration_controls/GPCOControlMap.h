//
// Created by vydra on 7/31/20.
//

#pragma once

#include <map>

#include "./BearLibTerminal.h"
#include "adds/log_systems/PseudoLogSystem.hpp"
#include "entities/data_entities/GameConfigurationData.hpp"
#include "entities/data_entities/ParameterQueryData.hpp"
#include "systems/IControl.h"
#include "systems/scenes_systems/configuration_systems/controls/sub_controls/game_play_configuration_controls/GPCOControlSelectDown.h"
#include "systems/scenes_systems/configuration_systems/controls/sub_controls/game_play_configuration_controls/GPCOControlSelectEmpty.h"
#include "systems/scenes_systems/configuration_systems/controls/sub_controls/game_play_configuration_controls/GPCOControlSelectEnter.h"
#include "systems/scenes_systems/configuration_systems/controls/sub_controls/game_play_configuration_controls/GPCOControlSelectExit.h"
#include "systems/scenes_systems/configuration_systems/controls/sub_controls/game_play_configuration_controls/GPCOControlSelectUp.h"

class GPCOControlMap {
 private:
  GPCOControlSelectExit *exit = nullptr;
  GPCOControlSelectEmpty *empty = nullptr;
  GPCOControlSelectEnter *enter = nullptr;
  GPCOControlSelectDown *down = nullptr;
  GPCOControlSelectUp *up = nullptr;

  std::map<int, IControl *> c_map;
  std::map<int, IControl *>::iterator c_iterator;

 public:
  explicit GPCOControlMap(ParameterQueryData *input_configuration_data,
                          GameConfigurationData *input_global_configuration_data) {
    down = new GPCOControlSelectDown(input_configuration_data);
    up = new GPCOControlSelectUp(input_configuration_data);
    exit = new GPCOControlSelectExit();
    empty = new GPCOControlSelectEmpty();
    enter = new GPCOControlSelectEnter(input_configuration_data, input_global_configuration_data);

    c_map.insert(std::make_pair(TK_CLOSE, exit));
    c_map.insert(std::make_pair(TK_ESCAPE, exit));
    c_map.insert(std::make_pair(TK_ENTER, enter));
    c_map.insert(std::make_pair(TK_UP, up));
    c_map.insert(std::make_pair(TK_DOWN, down));
  }

  ~GPCOControlMap() {
    delete exit;
    delete empty;
    delete enter;
    delete down;
    delete up;
  }

  IControl *get_control(TERMINAL_API int input_key) {
    c_iterator = c_map.find(input_key);
    if (c_iterator == c_map.end()) {
      return empty;
    }
    return c_iterator->second;
  }
};
