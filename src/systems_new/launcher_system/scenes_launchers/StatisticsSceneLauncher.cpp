//
// Created by vydra on 8/21/20.
//

#include "systems_new/launcher_system/scenes_launchers/StatisticsSceneLauncher.hpp"

StatisticsSceneLauncher::StatisticsSceneLauncher(IRenderSystem *input_render_system, SceneType *input_scene_type)
    : IControl("StatisticsSceneLauncher") {
  render_system = input_render_system;
  scene_type = input_scene_type;
}

StatisticsSceneLauncher::~StatisticsSceneLauncher() = default;

void StatisticsSceneLauncher::execute() {
  PseudoLogSystem::log(get_name(), "Launch score list scene");
  auto *scene = new StatisticsScene(render_system);
  scene->run();
  delete scene;
  *scene_type = MAIN_MENU_SCENE;
}
