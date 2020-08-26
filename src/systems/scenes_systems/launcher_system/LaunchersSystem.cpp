//
// Created by vydra on 8/21/20.
//

#include "systems/scenes_systems/launcher_system/LaunchersSystem.hpp"

void LaunchersSystem::run() {
  printf("%s", "starting...\n");
  printf("%s", "--------re.TESFalkreath--------\n");
  auto *main_map = new ScenesLaunchersManager();
  IControl *main_control;

  main_control = main_map->get_control(main_map->get_highlighted());
  do {
    main_control->execute();
    main_control = main_map->get_control(main_map->get_highlighted());
  } while (std::strcmp(main_control->get_name(), "LauncherExitScene") != 0);

  delete main_map;
}
