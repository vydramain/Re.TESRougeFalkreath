//
// Created by vydra on 8/18/20.
//

#pragma once

#include "entities/render_entities/IRender.h"
#include "entities/render_entities/TextPanelsRender.h"

class GameLoopEndingRender : public IRender {
 private:
  unsigned SCREENMODE_X = 0;
  unsigned SCREENMODE_Y = 0;

  static const unsigned EXIT_CHOICE = 2;
  const char *const question = "Сохранить статистику?";
  const char *choices[EXIT_CHOICE] = {"Да", "Нет"};
  const unsigned count_choices = EXIT_CHOICE;
  unsigned *highlighted = nullptr;

 public:
  explicit GameLoopEndingRender(unsigned *input_highlighted);
  ~GameLoopEndingRender() override;

  void update_fields(unsigned input_screen_x, unsigned input_screen_y);

  void render() override;
};