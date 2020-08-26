//
// Created by vydra on 12.07.2020.
//

#include "entities/scenes_entities/main_menu_scene/MainMenuScene.h"

MainMenuScene::MainMenuScene(IRenderSystem *input_render_system) : IMainScene("MainMenuScene") {
  mm_input = new MMControls(count_choices, highlighted);

  render_system = input_render_system;
  render_system->set_main_menu_data(title, choices, count_choices, highlighted);
  render_system->set_main_menu_render();
}
MainMenuScene::~MainMenuScene() {
  render_system = nullptr;
  delete mm_input;
}

unsigned MainMenuScene::get_highlighted() const {
  return *highlighted;
}
void MainMenuScene::run() {
  printf("%s", "[MainMenuScene] - Launch main menu\n");
  do {
    render_system->render();
    last_control = mm_input->update();
    last_control->execute();
  } while (std::strcmp(last_control->get_name(), "MMControlSelectExit") != 0 &&
           std::strcmp(last_control->get_name(), "MMControlSelectEnter") != 0);

  if (std::strcmp(last_control->get_name(), "MMControlSelectExit") == 0) {
    *highlighted = EXIT_CHOICE;
  }
}
