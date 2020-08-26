//
// Created by vydra on 8/21/20.
//

#include "systems_new/launcher_system/scenes_launchers/GameLoopSceneLauncher.h"

GameLoopSceneLauncher::GameLoopSceneLauncher(IRenderSystem *input_render_system, SceneType *input_scene_type)
    : IControl("GameLoopSceneLauncher") {
  render_system = input_render_system;
  scene_type = input_scene_type;
}

GameLoopSceneLauncher::~GameLoopSceneLauncher() = default;

void GameLoopSceneLauncher::execute() {
  PseudoLogSystem::log(get_name(), "Launch game loop scene");
  auto *scene = new GameLoopScene(render_system);
  scene->run();
  delete scene;
  *scene_type = MAIN_MENU_SCENE;
}
