//
// Created by vydra on 7/31/20.
//

#pragma once

#include <map>

#include "systems/pseudo_log_systems/PseudoLogSystem.hpp"
#include "systems/scenes_systems/scenes_launchers/LauncherExitScene.h"
#include "systems/scenes_systems/scenes_launchers/LauncherGameLoopScene.h"
#include "systems/scenes_systems/scenes_launchers/LauncherMainMenuScene.h"
#include "systems/scenes_systems/scenes_launchers/LauncherScoreListScene.hpp"

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
