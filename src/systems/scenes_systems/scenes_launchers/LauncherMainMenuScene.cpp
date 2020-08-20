//
// Created by vydra on 8/21/20.
//

#include "systems/scenes_systems/scenes_launchers/LauncherMainMenuScene.h"

LauncherMainMenuScene::LauncherMainMenuScene(IRenderSystem *input_system, unsigned int *input_pointer)
    : IControl("LauncherMainMenuScene"), render_system(input_system), highlighted(input_pointer) {}

LauncherMainMenuScene::~LauncherMainMenuScene() {}

void LauncherMainMenuScene::execute() {
  PseudoLogSystem::log(get_name(), "Launch main menu");
  auto *main_scene = new MainMenuScene(render_system);
  main_scene->run();
  *highlighted = main_scene->get_highlighted();
  delete main_scene;
}
