//
// Created by vydra on 8/21/20.
//

#include "systems_new/launcher_system/scenes_launchers/LauncherScoreListScene.hpp"

LauncherScoreListScene::LauncherScoreListScene(IRenderSystem *input_render_system, unsigned int *input_pointer)
    : IControl("LauncherScoreListScene"), render_system(input_render_system), highlighted(input_pointer) {}

LauncherScoreListScene::~LauncherScoreListScene() {}

void LauncherScoreListScene::execute() {
  PseudoLogSystem::log(get_name(), "Launch score list scene");
  *highlighted = 0;
  auto *scene = new ScoreListScene(render_system);
  scene->run();
  delete scene;
}
