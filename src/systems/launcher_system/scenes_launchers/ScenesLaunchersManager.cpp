//
// Created by vydra on 8/21/20.
//

#include "systems/launcher_system/scenes_launchers/ScenesLaunchersManager.h"

ScenesLaunchersManager::ScenesLaunchersManager(GameConfigurationData* input_configuration_data) {
  PseudoLogSystem::log("ScenesLaunchersManager", "Launch BearLibTerminal's render system");
  render = new BearRenderSystem(input_configuration_data->get_resolution());
  expected_scene = new SceneType(MAIN_MENU_SCENE);

  PseudoLogSystem::log("ScenesLaunchersManager", "Creating expected scene's controls launchers");
  exit = new ExitSceneLauncher();
  new_game = new GameLoopSceneLauncher(render, expected_scene, input_configuration_data);
  main_menu = new MainMenuSceneLauncher(render, expected_scene);
  configuration = new ConfigurationSceneLauncher(render, expected_scene, input_configuration_data);
  score_list = new StatisticsSceneLauncher(render, expected_scene);

  main_map[MAIN_MENU_SCENE] = main_menu;
  main_map[NEW_GAME_SCENE] = new_game;
  main_map[SETTINGS_SCENE] = configuration;
  main_map[SCORE_LIST_SCENE] = score_list;
  main_map[EXIT_SCENE] = exit;
}

ScenesLaunchersManager::~ScenesLaunchersManager() {
  PseudoLogSystem::log("ScenesLaunchersManager", "Deleting expected scene's controls launchers");
  main_map.clear();

  delete exit;
  delete main_menu;
  delete new_game;
  delete configuration;
  delete score_list;

  delete render;
  delete expected_scene;
}

SceneType ScenesLaunchersManager::get_expected_scene_type() const {
  return *expected_scene;
}

IControl* ScenesLaunchersManager::get_control(SceneType input_scene_type) {
  main_iterator = main_map.find(input_scene_type);
  if (main_iterator == main_map.end()) {
    return exit;
  }
  return main_iterator->second;
}

void ScenesLaunchersManager::reconfiguration_systems(GameConfigurationData* input_configuration_data) {
  if (input_configuration_data->has_changes()) {
    render->reset_render();
    if (input_configuration_data->get_resolution()->get_current_resolution() == AbsResolution::R_1280x720) {
      render->set_resolution_1280x720();
    }
    if (input_configuration_data->get_resolution()->get_current_resolution() == AbsResolution::R_1920x1080) {
      render->set_resolution_1920x1080();
    }
  }
}
