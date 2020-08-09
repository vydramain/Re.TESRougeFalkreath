//
// Created by vydra on 12.07.2020.
//

#include "core/entities/scenes_entities/main_menu_scene/MainMenuScene.h"

MainMenuScene::MainMenuScene() : IMainScene("main_menu") {
  render = new main_menu_render();
  mm_input = new MMControls(count_choices, highlighted);
}
MainMenuScene::~MainMenuScene() {
  delete render;
  delete mm_input;
}

unsigned MainMenuScene::get_highlighted() const {
  return *highlighted;
}
void MainMenuScene::run() {
  do {
    render->view_choice(title, choices, count_choices, *highlighted);
    render->render();

    last_control = mm_input->update();
    last_control->execute();
  } while (std::strcmp(last_control->get_name(), "MMControlSelectExit") != 0 &&
           std::strcmp(last_control->get_name(), "MMControlSelectEnter") != 0);

  if (std::strcmp(last_control->get_name(), "MMControlSelectExit") == 0) {
    *highlighted = EXIT_CHOICE;
  }
}