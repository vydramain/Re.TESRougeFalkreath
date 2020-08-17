//
// Created by vydra on 8/17/20.
//

#pragma once

#include <cstring>

#include "entities/scenes_entities/IScene.h"
#include "systems/location_systems/LocationSystem.h"
#include "systems/controls_systems/game_loop_controls/sub_controls/ending_controls/GLEControls.h"

class EndingScene : public IScene {
 private:
  GLEControls *gle_input;
  IControl *last_control = nullptr;

  static const unsigned EXIT_CHOICE = 2;
  const char *const question = "Сохранить статистику?";
  const char *choices[EXIT_CHOICE] = {"Да", "Нет"};
  const unsigned count_choices = EXIT_CHOICE;
  unsigned *highlighted = new unsigned(1);

 public:
  explicit EndingScene(LocationSystem *input_location);
  ~EndingScene() override;

  IControl *get_last_control();

  void run() override;
};