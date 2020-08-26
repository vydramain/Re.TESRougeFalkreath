//
// Created by vydra on 8/21/20.
//

#include "systems_new/launcher_system/scenes_launchers/ScenesLaunchersManager.h"

ScenesLaunchersManager::ScenesLaunchersManager() {
  PseudoLogSystem::log("ScenesLaunchersManager", "Launch BearLibTerminal's render system");
  render = new BearRenderSystem();
  last_highlighted = new unsigned(0);

  PseudoLogSystem::log("ScenesLaunchersManager", "Creating global controls");
  exit = new LauncherExitScene();
  main_menu = new LauncherMainMenuScene(render, last_highlighted);
  new_game = new LauncherGameLoopScene(render, last_highlighted);
  score_list = new LauncherScoreListScene(render, last_highlighted);

  main_map[0] = main_menu;
  main_map[1] = new_game;
  main_map[2] = score_list;
  main_map[3] = exit;
}

ScenesLaunchersManager::~ScenesLaunchersManager() {
  PseudoLogSystem::log("ScenesLaunchersManager", "Deleting global controls");
  main_map.clear();

  delete exit;
  delete main_menu;
  delete new_game;
  delete score_list;

  delete last_highlighted;
  delete render;
}

unsigned ScenesLaunchersManager::get_highlighted() const {
  return *last_highlighted;
}

IControl* ScenesLaunchersManager::get_control(unsigned int input_highlighted) {
  main_iterator = main_map.find(input_highlighted);
  if (main_iterator == main_map.end()) {
    return exit;
  }
  return main_iterator->second;
}
