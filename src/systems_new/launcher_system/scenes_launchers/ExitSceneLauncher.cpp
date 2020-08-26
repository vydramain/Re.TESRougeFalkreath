//
// Created by vydra on 8/21/20.
//

#include "systems_new/launcher_system/scenes_launchers/ExitSceneLauncher.h"

ExitSceneLauncher::ExitSceneLauncher() : IControl("ExitSceneLauncher") {}
ExitSceneLauncher::~ExitSceneLauncher() {}

void ExitSceneLauncher::execute() {
  PseudoLogSystem::log(get_name(), "Exit the Scenes system");
}
