//
// Created by vydra on 8/21/20.
//

#include "systems/scenes_systems/launcher_system/scenes_launchers/LauncherExitScene.h"

LauncherExitScene::LauncherExitScene() : IControl("LauncherExitScene") {}
LauncherExitScene::~LauncherExitScene() {}

void LauncherExitScene::execute() {
  PseudoLogSystem::log(get_name(), "Exit the Scenes system");
}
