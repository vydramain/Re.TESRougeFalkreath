//
// Created by vydra on 8/21/20.
//

#include "systems/launcher_system/scenes_launchers/GameLoopSceneLauncher.h"

GameLoopSceneLauncher::GameLoopSceneLauncher(IRenderSystem *input_render_system, SceneType *input_scene_type,
                                             GameConfigurationData *input_settings_data)
    : IControl("GameLoopSceneLauncher") {
  settings_data = input_settings_data;
  render_system = input_render_system;
  scene_type = input_scene_type;
}

GameLoopSceneLauncher::~GameLoopSceneLauncher() = default;

void GameLoopSceneLauncher::execute() {
  PseudoLogSystem::log(get_name(), "Launch game loop scene");
  auto *scene = new GameLoopScene(render_system, settings_data);
  scene->run();
  delete scene;
  *scene_type = MAIN_MENU_SCENE;
}
