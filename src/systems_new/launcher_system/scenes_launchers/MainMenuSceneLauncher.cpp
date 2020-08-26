//
// Created by vydra on 8/21/20.
//

#include "systems_new/launcher_system/scenes_launchers/MainMenuSceneLauncher.h"

MainMenuSceneLauncher::MainMenuSceneLauncher(IRenderSystem *input_render_system, SceneType *input_scene_type)
    : IControl("MainMenuSceneLauncher") {
  render_system = input_render_system;
  scene_type = input_scene_type;
}

MainMenuSceneLauncher::~MainMenuSceneLauncher() {}

void MainMenuSceneLauncher::execute() {
  PseudoLogSystem::log(get_name(), "Launch main menu scene");
  auto *scene = new MainMenuScene(render_system);
  scene->run();
  *scene_type = scene->get_highlighted();
  delete scene;
}
