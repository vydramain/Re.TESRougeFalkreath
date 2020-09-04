//
// Created by vydra on 8/21/20.
//

#include "systems/launcher_system/scenes_launchers/ExitSceneLauncher.h"

ExitSceneLauncher::ExitSceneLauncher() : IControl("ExitSceneLauncher") {}
ExitSceneLauncher::~ExitSceneLauncher() = default;

void ExitSceneLauncher::execute() {
  PseudoLogSystem::log(get_name(), "Launch exit scene");
}
