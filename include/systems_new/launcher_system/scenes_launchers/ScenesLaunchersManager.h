//
// Created by vydra on 7/31/20.
//

#pragma once

#include <map>

#include "ExitSceneLauncher.h"
#include "GameLoopSceneLauncher.h"
#include "MainMenuSceneLauncher.h"
#include "ScoreListSceneLauncher.hpp"
#include "adds/log_systems/PseudoLogSystem.hpp"
#include "systems/controls_systems/IControl.h"
#include "systems/render_systems/BearRenderSystem.h"
#include "systems/render_systems/IRenderSystem.h"

enum SceneType { MAIN_MENU_SCENE = 0, NEW_GAME_SCENE = 1, SCORE_LIST_SCENE = 2, EXIT_SCENE = 3, };

class ScenesLaunchersManager {
 private:
  ExitSceneLauncher *exit = nullptr;
  GameLoopSceneLauncher *new_game = nullptr;
  MainMenuSceneLauncher *main_menu = nullptr;
  ScoreListSceneLauncher *score_list = nullptr;

  std::map<SceneType, IControl *> main_map;
  std::map<SceneType, IControl *>::iterator main_iterator;

  IRenderSystem *render = nullptr;
  SceneType *scene;

 public:
  explicit ScenesLaunchersManager();
  ~ScenesLaunchersManager();

  SceneType get_scene_type() const;
  IControl *get_control(SceneType input_scene_type);
};
