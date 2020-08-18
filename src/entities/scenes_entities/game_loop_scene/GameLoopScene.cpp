//
// Created by vydra on 15.07.2020.
//

#include "entities/scenes_entities/game_loop_scene/GameLoopScene.h"

GameLoopScene::GameLoopScene(IRenderSystem *input_system, unsigned input_x, unsigned input_y,
                             LocationsEntitiesSystem *input_entities)
    : IMainScene("MainLoopScene"),
      render_system(input_system),
      location(new LocationSystem(input_x, input_y, input_entities)) {
  render_system->set_pseudo_game_loop_render();
}

GameLoopScene::~GameLoopScene() {
  render_system = nullptr;
  delete location;
}

void GameLoopScene::run() {
  printf("%s", "[GameLoopScene] - Launch game loop\n");
  auto *ml_control_map = new GLControlMap(location);
  printf("%s", "[GLControl] - Set start control\n");
  IGLControl *current_ml_control = ml_control_map->get_start_control();

  do {
    render_system->render();
    current_ml_control->execute();
    current_ml_control = ml_control_map->get_control(current_ml_control->get_last_control());
  } while (std::strcmp(current_ml_control->get_name(), "GLControlExit") != 0);
  delete ml_control_map;
}
