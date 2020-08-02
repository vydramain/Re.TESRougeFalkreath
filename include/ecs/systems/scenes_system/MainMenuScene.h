//
// Created by vydra on 12.07.2020.
//

#ifndef INCLUDE_ECS_SYSTEMS_SCENES_SYSTEM_MAINMENUSCENE_H_
#define INCLUDE_ECS_SYSTEMS_SCENES_SYSTEM_MAINMENUSCENE_H_

#include <ecs/systems/controls_system/menu_controls/MMControls.h>

#include "ecs/systems/render_system/main_menu_render.h"
#include "ecs/systems/scenes_system/IMainScene.h"

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
  ~MainMenuScene();

  void run() override;
};

#endif  // INCLUDE_ECS_SYSTEMS_SCENES_SYSTEM_MAINMENUSCENE_H_
