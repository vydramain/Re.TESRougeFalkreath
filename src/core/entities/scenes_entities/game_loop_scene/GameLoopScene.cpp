//
// Created by vydra on 15.07.2020.
//

#include "core/entities/scenes_entities/game_loop_scene/GameLoopScene.h"

GameLoopScene::GameLoopScene(const char *input_area_name, Area *input_area, LocationsEntitiesSystem *input_entities)
    : IMainScene("MainLoopScene") {
  location = new LocationSystem(input_area, input_entities);

  render = new game_loop_render(location);
}

GameLoopScene::~GameLoopScene() {
  delete location;
  delete render;
}

void GameLoopScene::run() {
  auto *ml_control_map = new GLControlMap(location);
  IGLControl *current_ml_control = ml_control_map->get_start_control();

  do {
    render->render();
    current_ml_control->execute();
    current_ml_control = ml_control_map->get_control(current_ml_control->get_last_control());
  } while (std::strcmp(current_ml_control->get_name(), "GLControlExit") != 0);
  delete ml_control_map;
}
