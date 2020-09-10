//
// Created by vydra on 8/21/20.
//

#include "systems/launcher_system/LaunchersSystem.hpp"

#include "entities/GameConfigurationData.hpp"

void LaunchersSystem::run() {
  printf("%s", "starting...\n");
  printf("%s", "--------re.TESFalkreath--------\n");

  auto *configuration_data = new GameConfigurationData();

  IControl *launcher_scene;
  auto *launcher_map = new ScenesLaunchersManager(configuration_data);
  launcher_scene = launcher_map->get_control(launcher_map->get_expected_scene_type());

  do {
    launcher_scene->execute();
    launcher_scene = launcher_map->get_control(launcher_map->get_expected_scene_type());
    launcher_map->reconfiguration_systems(configuration_data);
  } while (std::strcmp(launcher_scene->get_name(), "ExitSceneLauncher") != 0);

  delete launcher_map;
  delete configuration_data;
}
