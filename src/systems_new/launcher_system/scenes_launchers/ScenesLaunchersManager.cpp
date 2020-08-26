//
// Created by vydra on 8/21/20.
//

#include "systems_new/launcher_system/scenes_launchers/ScenesLaunchersManager.h"

ScenesLaunchersManager::ScenesLaunchersManager() {
  PseudoLogSystem::log("ScenesLaunchersManager", "Launch BearLibTerminal's render system");
  render = new BearRenderSystem();
  scene = new SceneType(MAIN_MENU_SCENE);

  PseudoLogSystem::log("ScenesLaunchersManager", "Creating scene's launchers");
  exit = new ExitSceneLauncher();
  new_game = new GameLoopSceneLauncher(render, scene);
  main_menu = new MainMenuSceneLauncher(render, scene);
  score_list = new ScoreListSceneLauncher(render, scene);

  main_map[MAIN_MENU_SCENE] = main_menu;
  main_map[NEW_GAME_SCENE] = new_game;
  main_map[SCORE_LIST_SCENE] = score_list;
  main_map[EXIT_SCENE] = exit;
}

ScenesLaunchersManager::~ScenesLaunchersManager() {
  PseudoLogSystem::log("ScenesLaunchersManager", "Deleting global controls");
  main_map.clear();

  delete exit;
  delete main_menu;
  delete new_game;
  delete score_list;

  delete render;
  delete scene;
}

SceneType ScenesLaunchersManager::get_scene_type() const {
  return *scene;
}

IControl* ScenesLaunchersManager::get_control(SceneType input_scene_type) {
  main_iterator = main_map.find(input_scene_type);
  if (main_iterator == main_map.end()) {
    return exit;
  }
  return main_iterator->second;
}
