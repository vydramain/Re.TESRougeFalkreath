//
// Created by vydra on 15.07.2020.
//

#include "entities/scenes_entities/game_loop_scene/GameLoopScene.h"

#include <string>

GameLoopScene::GameLoopScene(IRenderSystem *input_render_system, GameSettingsData *input_settings_data)
    : IMainScene("MainLoopScene") {
  auto **menu_choice = new std::string *[2];
  menu_choice[0] = new std::string("Да");
  menu_choice[1] = new std::string("Нет");
  ending_data = new ParameterQueryData(new std::string("Сохранить статистику?"), 2, menu_choice);

  settings_data = input_settings_data;
  render_system = input_render_system;
  world_system = new WorldSystem();
}

GameLoopScene::~GameLoopScene() {
  render_system = nullptr;
  delete world_system;
}

void GameLoopScene::run() {
  PseudoLogSystem::log(get_name(), "Launch game loop");
  auto *gl_control_map = new GLControlMap(render_system, world_system, ending_data, settings_data);
  PseudoLogSystem::log(get_name(), "Set start control");
  IGLControl *current_gl_control = gl_control_map->get_start_control();
  if (std::strcmp(current_gl_control->get_name(), "GLControlExit") == 0) {
    return;
  }
  PseudoLogSystem::log(get_name(), "Setting up render system");
  render_system->set_game_loop_data(world_system, ending_data);
  render_system->set_pseudo_game_loop_render();

  do {
    render_system->render();
    current_gl_control->execute();
    current_gl_control = gl_control_map->get_control(current_gl_control->get_last_executed_control());
  } while (std::strcmp(current_gl_control->get_name(), "GLControlExit") != 0);

  delete gl_control_map;
}
