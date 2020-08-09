//
// Created by vydra on 15.07.2020.
//

#include "core/entities/scenes_entities/game_loop_scene/GameLoopScene.h"

GameLoopScene::GameLoopScene(const char *input_area_name, Area *input_area, Races *input_races,
                             Creatures *input_creatures, Items *input_items)
    : IMainScene("MainLoopScene") {
  location = new Location(input_area_name, input_area, input_races, input_creatures, input_items);

  render = new game_loop_render(location, input_creatures);
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
