//
// Created by vydra on 15.07.2020.
//

#include "entities/scenes_entities/game_loop_scene/GameLoopScene.h"

#include <string>

GameLoopScene::GameLoopScene(IRenderSystem *input_render_system, GameConfigurationData *input_settings_data)
    : IMainScene("MainLoopScene") {
  const char *ending_choice[2] = {"Да", "Нет"};
  data = new ParameterQueryDataSet();
  data->insert_data(new ParameterQueryData(new std::string("statistic_data"), new std::string("Сохранить статистику?"),
                                           ParameterQueryData::create_choices(2, ending_choice)));
  const char *combat_choice[2] = {"Ударить", "Сбежать"};
  data->insert_data(new ParameterQueryData(new std::string("combat_data"), new std::string("Действие:"),
                                           ParameterQueryData::create_choices(2, combat_choice)));

  settings_data = input_settings_data;
  render_system = input_render_system;
  world_system = new WorldSystem();
}

GameLoopScene::~GameLoopScene() {
  render_system = nullptr;
  delete world_system;
  delete data;
}

void GameLoopScene::run() {
  PseudoLogSystem::log(get_name()->data(), "Launch game loop");
  auto *gl_control_map = new GLControlMap(render_system, world_system, data, settings_data);
  PseudoLogSystem::log(get_name()->data(), "Set start control");
  IGLControl *current_gl_control = gl_control_map->get_start_control();
  if (std::strcmp(current_gl_control->get_name(), "GLControlExit") == 0) {
    return;
  }
  PseudoLogSystem::log(get_name()->data(), "Setting up render system");
  render_system->set_game_loop_data(world_system, data);
  render_system->set_pseudo_game_loop_render();

  do {
    render_system->render();
    current_gl_control->execute();
    current_gl_control = gl_control_map->get_control(current_gl_control->get_last_executed_control());
  } while (std::strcmp(current_gl_control->get_name(), "GLControlExit") != 0);

  delete gl_control_map;
}
