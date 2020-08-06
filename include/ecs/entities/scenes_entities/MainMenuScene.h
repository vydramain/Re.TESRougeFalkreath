//
// Created by vydra on 12.07.2020.
//

#pragma once

#include "ecs/entities/scenes_entities/IMainScene.h"
#include "ecs/systems/controls_system/menu_controls/MMControls.h"
#include "ecs/systems/render_system/main_menu_render.h"

class MainMenuScene : public IMainScene {
 private:
  main_menu_render *render;
  MMControls *mm_input;
  IControl *last_control = nullptr;

  const char *const title = "Главное меню:";
  const char *choices[2] = {"Играть", "Выход"};
  const unsigned count_choices = 2;
  unsigned *highlighted = new unsigned(0);

 public:
  explicit MainMenuScene();
  ~MainMenuScene() override;

  void run() override;
};
