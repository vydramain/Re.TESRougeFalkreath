//
// Created by vydra on 9/5/20.
//

#include "systems/launcher_system/scenes_launchers/ConfigurationSceneLauncher.hpp"

ConfigurationSceneLauncher::ConfigurationSceneLauncher(IRenderSystem *input_render_system, SceneType *input_scene_type,
                                             GameConfigurationData *input_settings_data)
    : IControl("ConfigurationSceneLauncher") {
  settings_data = input_settings_data;
  render_system = input_render_system;
  scene_type = input_scene_type;
}

ConfigurationSceneLauncher::~ConfigurationSceneLauncher() = default;

void ConfigurationSceneLauncher::execute() {
  PseudoLogSystem::log(get_name(), "Launch settings scene");
  auto *scene = new ConfigurationScene(render_system, settings_data);
  scene->run();
  *scene_type = MAIN_MENU_SCENE;
  delete scene;
}
