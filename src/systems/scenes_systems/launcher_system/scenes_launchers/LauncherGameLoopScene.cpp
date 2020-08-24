//
// Created by vydra on 8/21/20.
//

#include "systems/scenes_systems/launcher_system/scenes_launchers/LauncherGameLoopScene.h"

LauncherGameLoopScene::LauncherGameLoopScene(IRenderSystem *input_system, unsigned int *input_pointer)
    : IControl("GlobalControlNewGame"), render_system(input_system), highlighted(input_pointer) {}

LauncherGameLoopScene::~LauncherGameLoopScene() {}

void LauncherGameLoopScene::execute() {
  PseudoLogSystem::log(get_name(), "Launch game loop scene");
  *highlighted = 0;
  auto *main_scene = new GameLoopScene(render_system);
  main_scene->run();
  delete main_scene;
}
