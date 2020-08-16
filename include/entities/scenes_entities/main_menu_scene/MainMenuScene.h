//
// Created by vydra on 12.07.2020.
//

#pragma once

#include <cstring>

#include "systems/controls_systems/main_menu_controls/MMControls.h"
#include "systems/render_systems/RenderSystem.h"
#include "entities/scenes_entities/IMainScene.h"

class MainMenuScene : public IMainScene {
 private:
  RenderSystem *render_system = nullptr;
  static const unsigned EXIT_CHOICE = 2;

  MMControls *mm_input = nullptr;
  IControl *last_control = nullptr;

  const char *const title = "Главное меню:";
  const char *choices[EXIT_CHOICE] = {"Играть", "Выход"};
  const unsigned count_choices = EXIT_CHOICE;
  unsigned *highlighted = new unsigned(1);

 public:
  explicit MainMenuScene(RenderSystem *input_system);
  ~MainMenuScene() override;

  unsigned get_highlighted() const;

  void run() override;
};
