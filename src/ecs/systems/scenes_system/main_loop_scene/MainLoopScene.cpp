//
// Created by vydra on 15.07.2020.
//

#include "ecs/systems/scenes_system/main_loop_scene/MainLoopScene.h"

#include <cstring>

#include "ecs/systems/controls_system/loop_controls/main_loop_scene_controls/MLControlMap.h"

MainLoopScene::MainLoopScene(const char *input_area_name, Map *input_area, Creatures *input_creatures,
                             Items *input_items)
    : IMainScene("MainLoopScene") {
  location = new Location(input_area_name, input_area, input_creatures, input_items);

  render = new game_loop_render(location, input_creatures);
}

MainLoopScene::~MainLoopScene() {
  delete render;
}

void MainLoopScene::run() {
  auto *ml_control_map = new MLControlMap(location);
  IMLControl *current_ml_control = ml_control_map->get_start_control();

  do {
    render->render();
    current_ml_control->execute();
    current_ml_control = ml_control_map->get_control(current_ml_control->get_last_control());
  } while (std::strcmp(current_ml_control->get_name(), "MLControlExit") != 0);
  delete ml_control_map;
}
