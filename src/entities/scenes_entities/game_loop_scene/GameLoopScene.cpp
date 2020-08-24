//
// Created by vydra on 15.07.2020.
//

#include "entities/scenes_entities/game_loop_scene/GameLoopScene.h"

GameLoopScene::GameLoopScene(IRenderSystem *input_render_system) : IMainScene("MainLoopScene") {
  render_system = input_render_system;
  location_system = new LocationSystem();
}

GameLoopScene::~GameLoopScene() {
  render_system = nullptr;
  delete location_system;
}

void GameLoopScene::run() {
  PseudoLogSystem::log(get_name(), "Launch game loop");
  auto *gl_control_map = new GLControlMap(location_system, ending_count, ending_highlighted);
  PseudoLogSystem::log(get_name(), "Set start control");
  IGLControl *current_gl_control = gl_control_map->get_start_control();
  PseudoLogSystem::log(get_name(), "Setting up render system");
  render_system->set_game_loop_data(location_system, ending_highlighted);
  render_system->set_pseudo_game_loop_render();

  do {
    render_system->render();
    current_gl_control->execute();
    current_gl_control = gl_control_map->get_control(current_gl_control->get_last_executed_control());
  } while (std::strcmp(current_gl_control->get_name(), "GLControlExit") != 0);

  delete gl_control_map;
}
