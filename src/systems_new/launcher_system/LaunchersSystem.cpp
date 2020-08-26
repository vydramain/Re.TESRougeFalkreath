//
// Created by vydra on 8/21/20.
//

#include "systems_new/launcher_system/LaunchersSystem.hpp"

void LaunchersSystem::run() {
  printf("%s", "starting...\n");
  printf("%s", "--------re.TESFalkreath--------\n");
  auto *launcher_map = new ScenesLaunchersManager();
  IControl *main_control;

  main_control = launcher_map->get_control(launcher_map->get_highlighted());
  do {
    main_control->execute();
    main_control = launcher_map->get_control(launcher_map->get_highlighted());
  } while (std::strcmp(main_control->get_name(), "LauncherExitScene") != 0);

  delete launcher_map;
}
