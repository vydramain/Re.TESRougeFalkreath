//
// Created by vydra on 12.07.2020.
//

#pragma once

#include <cstring>

#include "entities/scenes_entities/IMainScene.h"
#include "systems/controls_systems/scenes_controls/main_menu_controls/MMControls.h"
#include "systems/render_systems/BearRenderSystem.h"

class MainMenuScene : public IMainScene {
 private:
  IRenderSystem *render_system = nullptr;
  static const unsigned EXIT_CHOICE = 3;

  MMControls *mm_input = nullptr;
  IControl *last_control = nullptr;

  const char *const title = "Главное меню:";
  const char *choices[EXIT_CHOICE] = {"Играть", "Рейтинг", "Выход"};
  const unsigned count_choices = EXIT_CHOICE;
  unsigned *highlighted = new unsigned(1);

 public:
  explicit MainMenuScene(IRenderSystem *input_render_system);
  ~MainMenuScene() override;

  unsigned get_highlighted() const;

  void run() override;
};
