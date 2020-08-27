//
// Created by vydra on 15.07.2020.
//

#include "entities/scenes_entities/game_loop_scene/GameLoopScene.h"

GameLoopScene::GameLoopScene(IRenderSystem *input_render_system) : IMainScene("MainLoopScene") {
  auto **menu_choice = new std::string*[2];
  menu_choice[0] = new std::string("Да");
  menu_choice[1] = new std::string("Нет");
  ending_data = new MenuData(new std::string("Сохранить статистику?"), 2, menu_choice);

  render_system = input_render_system;
  location_system = new LocationSystem();
}

GameLoopScene::~GameLoopScene() {
  render_system = nullptr;
  delete location_system;
}

void GameLoopScene::run() {
  PseudoLogSystem::log(get_name(), "Launch game loop");
  auto *gl_control_map = new GLControlMap(render_system, location_system, ending_data);
  PseudoLogSystem::log(get_name(), "Set start control");
  IGLControl *current_gl_control = gl_control_map->get_start_control();
  PseudoLogSystem::log(get_name(), "Setting up render system");
  render_system->set_game_loop_data(location_system, ending_data);
  render_system->set_pseudo_game_loop_render();

  do {
    render_system->render();
    current_gl_control->execute();
    current_gl_control = gl_control_map->get_control(current_gl_control->get_last_executed_control());
  } while (std::strcmp(current_gl_control->get_name(), "GLControlExit") != 0);

  delete gl_control_map;
}
