//
// Created by vydra on 7/31/20.
//

#pragma once

#include <map>
#include <vector>

#include "./BearLibTerminal.h"
#include "adds/log_systems/PseudoLogSystem.hpp"
#include "systems/IControl.h"
#include "systems/launcher_system/data/GameConfigurationData.hpp"
#include "systems/launcher_system/data/ParameterQueryData.hpp"
#include "systems/scenes_systems/configuration_systems/controls/sub_controls/graphic_configuration_controls/GCOControlSelectDown.h"
#include "systems/scenes_systems/configuration_systems/controls/sub_controls/graphic_configuration_controls/GCOControlSelectEmpty.h"
#include "systems/scenes_systems/configuration_systems/controls/sub_controls/graphic_configuration_controls/GCOControlSelectEnter.h"
#include "systems/scenes_systems/configuration_systems/controls/sub_controls/graphic_configuration_controls/GCOControlSelectExit.h"
#include "systems/scenes_systems/configuration_systems/controls/sub_controls/graphic_configuration_controls/GCOControlSelectUp.h"

class GCOControlMap {
 private:
  GCOControlSelectExit *exit = nullptr;
  GCOControlSelectEmpty *empty = nullptr;
  GCOControlSelectEnter *enter = nullptr;
  GCOControlSelectDown *down = nullptr;
  GCOControlSelectUp *up = nullptr;

  std::map<int, IControl *> c_map;
  std::map<int, IControl *>::iterator c_iterator;

 public:
  explicit GCOControlMap(std::vector<ParameterQueryData *> *input_configuration_data,
                         GameConfigurationData *input_global_configuration_data) {
    exit = new GCOControlSelectExit(input_configuration_data);
    empty = new GCOControlSelectEmpty();
    enter = new GCOControlSelectEnter(input_configuration_data,
                                      input_global_configuration_data);
    down = new GCOControlSelectDown(input_configuration_data);
    up = new GCOControlSelectUp(input_configuration_data);

    c_map.insert(std::make_pair(TK_CLOSE, exit));
    c_map.insert(std::make_pair(TK_ESCAPE, exit));
    c_map.insert(std::make_pair(TK_ENTER, enter));
    c_map.insert(std::make_pair(TK_UP, up));
    c_map.insert(std::make_pair(TK_DOWN, down));
  }

  ~GCOControlMap() {
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
