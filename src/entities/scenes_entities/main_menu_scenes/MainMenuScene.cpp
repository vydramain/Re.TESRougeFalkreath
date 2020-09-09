//
// Created by vydra on 12.07.2020.
//

#include "entities/scenes_entities/main_menu_scene/MainMenuScene.h"

#include <string>

MainMenuScene::MainMenuScene(IRenderSystem *input_render_system) : IMainScene("MainMenuScene") {
  std::string temp_choices[4] = {"Новая игра", "Настройки", "Статистика", "Выход"};
  data =
      new ParameterQueryData(new std::string("Главное меню:"), ParameterQueryData::create_choices(4, temp_choices));

  mm_input = new MMControls(data);

  PseudoLogSystem::log("MainMenuScene", "Set up render system");
  render_system = input_render_system;
  render_system->set_main_menu_data(data);
  render_system->set_main_menu_render();
}
MainMenuScene::~MainMenuScene() {
  render_system = nullptr;
  delete mm_input;
}

unsigned MainMenuScene::get_highlighted() const {
  return data->get_highlighted();
}

void MainMenuScene::run() {
  PseudoLogSystem::log("MainMenuScene", "Launch main menu");
  do {
    render_system->render();
    last_control = mm_input->update();
    last_control->execute();
  } while (std::strcmp(last_control->get_name(), "MMControlSelectExit") != 0 &&
           std::strcmp(last_control->get_name(), "MMControlSelectEnter") != 0);

  if (std::strcmp(last_control->get_name(), "MMControlSelectExit") == 0) {
    data->set_highlighted(data->get_count_choices());
  }
}
