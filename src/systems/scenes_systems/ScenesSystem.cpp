//
// Created by vydra on 8/21/20.
//

#include "systems/scenes_systems/ScenesSystem.hpp"

void ScenesSystem::run() {
  printf("%s", "starting...\n");
  printf("%s", "--------re.TESFalkreath--------\n");
  auto *main_map = new GControlMap();
  IControl *main_control;

  main_control = main_map->get_control(main_map->get_highlighted());
  do {
    main_control->execute();
    main_control = main_map->get_control(main_map->get_highlighted());
  } while (std::strcmp(main_control->get_name(), "GControlExit") != 0);

  delete main_map;
}
