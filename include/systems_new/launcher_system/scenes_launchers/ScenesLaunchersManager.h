//
// Created by vydra on 7/31/20.
//

#pragma once

#include <map>

#include "LauncherExitScene.h"
#include "LauncherGameLoopScene.h"
#include "LauncherMainMenuScene.h"
#include "LauncherScoreListScene.hpp"
#include "adds/log_systems/PseudoLogSystem.hpp"

class ScenesLaunchersManager {
 private:
  LauncherExitScene *exit = nullptr;
  LauncherMainMenuScene *main_menu = nullptr;
  LauncherGameLoopScene *new_game = nullptr;
  LauncherScoreListScene *score_list = nullptr;

  std::map<unsigned, IControl *> main_map;
  std::map<unsigned, IControl *>::iterator main_iterator;

  IRenderSystem *render = nullptr;
  unsigned *last_highlighted = nullptr;

 public:
  explicit ScenesLaunchersManager();
  ~ScenesLaunchersManager();

  unsigned get_highlighted() const;
  IControl *get_control(unsigned input_highlighted);
};
