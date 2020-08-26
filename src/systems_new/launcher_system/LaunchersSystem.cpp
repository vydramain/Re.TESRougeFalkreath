//
// Created by vydra on 8/21/20.
//

#include "systems_new/launcher_system/LaunchersSystem.hpp"

void LaunchersSystem::run() {
  printf("%s", "starting...\n");
  printf("%s", "--------re.TESFalkreath--------\n");
  IControl *launcher_scene;
  auto *launcher_map = new ScenesLaunchersManager();
  launcher_scene = launcher_map->get_control(launcher_map->get_highlighted());

  do {
    launcher_scene->execute();
    launcher_scene = launcher_map->get_control(launcher_map->get_highlighted());
  } while (std::strcmp(launcher_scene->get_name(), "ExitSceneLauncher") != 0);

  delete launcher_map;
}
