//
// Created by vydra on 9/5/20.
//

#include "systems/launcher_system/scenes_launchers/SettingsSceneLauncher.hpp"

SettingsSceneLauncher::SettingsSceneLauncher(IRenderSystem *input_render_system, SceneType *input_scene_type)
    : IControl("SettingsSceneLauncher") {
  render_system = input_render_system;
  scene_type = input_scene_type;
}

SettingsSceneLauncher::~SettingsSceneLauncher() = default;

void SettingsSceneLauncher::execute() {
  PseudoLogSystem::log(get_name(), "Launch settings scene");
  auto *scene = new SettingsScene(render_system);
  scene->run();
  *scene_type = MAIN_MENU_SCENE;
  delete scene;
}
