//
// Created by vydra on 12.07.2020.
//

#include "core/entities/scenes_entities/main_menu_scene/MainMenuScene.h"

MainMenuScene::MainMenuScene(RenderSystem *input_system) : IMainScene("main_menu"), render_system(input_system) {
  mm_input = new MMControls(count_choices, highlighted);
  render_system->set_main_menu_render(title, choices, count_choices, highlighted);
}
MainMenuScene::~MainMenuScene() {
  delete mm_input;
}

unsigned MainMenuScene::get_highlighted() const {
  return *highlighted;
}
void MainMenuScene::run() {
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
