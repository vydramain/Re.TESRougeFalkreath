//
// Created by vydra on 12.07.2020.
//

#pragma once

#include <cstring>

#include "core/entities/scenes_entities/IMainScene.h"
#include "core/systems/controls_system/main_menu_controls/MMControls.h"
#include "ecs/systems/render_system/main_menu_render.h"

class MainMenuScene : public IMainScene {
 private:
  static const unsigned EXIT_CHOICE = 2;

  main_menu_render *render;
  MMControls *mm_input;
  IControl *last_control = nullptr;

  const char *const title = "Главное меню:";
  const char *choices[EXIT_CHOICE] = {"Играть", "Выход"};
  const unsigned count_choices = EXIT_CHOICE;
  unsigned *highlighted = new unsigned(1);

 public:
  explicit MainMenuScene();
  ~MainMenuScene() override;

  unsigned get_highlighted() const;

  void run() override;
};