//
// Created by vydra on 7/30/20.
//

#ifndef INCLUDE_ECS_SYSTEMS_CONTROLS_SYSTEM_LOOP_CONTROLS_MAIN_LOOP_ADVENTURE_SCENE_CONTROLS_MLACONTROLMAP_H_
#define INCLUDE_ECS_SYSTEMS_CONTROLS_SYSTEM_LOOP_CONTROLS_MAIN_LOOP_ADVENTURE_SCENE_CONTROLS_MLACONTROLMAP_H_

#include <BearLibTerminal.h>

#include <map>

#include "./MLAControlEmpty.h"
#include "./MLAControlExit.h"
#include "./MLAControlPlayerDown.h"
#include "./MLAControlPlayerLeft.h"
#include "./MLAControlPlayerRight.h"
#include "./MLAControlPlayerUp.h"

class MLAControlMap {
 private:
  MLAControlExit *control_exit = new MLAControlExit();
  MLAControlEmpty *control_empty = new MLAControlEmpty();
  MLAControlPlayerDown *control_player_down;
  MLAControlPlayerLeft *control_player_left;
  MLAControlPlayerRight *control_player_right;
  MLAControlPlayerUp *control_player_up;

  std::map<int, IControl *> mlas_map;
  std::map<int, IControl *>::iterator mlas_iterator;

 public:
  explicit MLAControlMap(Location *input_location) {
    control_player_down = new MLAControlPlayerDown(input_location);
    control_player_left = new MLAControlPlayerLeft(input_location);
    control_player_right = new MLAControlPlayerRight(input_location);
    control_player_up = new MLAControlPlayerUp(input_location);

    mlas_map[TK_CLOSE] = control_exit;
    mlas_map[TK_ESCAPE] = control_exit;
    mlas_map[TK_DOWN] = control_player_down;
    mlas_map[TK_LEFT] = control_player_left;
    mlas_map[TK_RIGHT] = control_player_right;
    mlas_map[TK_UP] = control_player_up;

    mlas_iterator = mlas_map.begin();
  }

  ~MLAControlMap() {
    delete control_exit;
    delete control_empty;
    delete control_player_down;
    delete control_player_left;
    delete control_player_right;
    delete control_player_up;
  }

  IControl *get_control(TERMINAL_API int input_key) {
    mlas_iterator = mlas_map.find(input_key);
    if (mlas_iterator == mlas_map.end()) {
      return control_empty;
    }
    return mlas_iterator->second;
  }
};

#endif  // INCLUDE_ECS_SYSTEMS_CONTROLS_SYSTEM_LOOP_CONTROLS_MAIN_LOOP_ADVENTURE_SCENE_CONTROLS_MLACONTROLMAP_H_
