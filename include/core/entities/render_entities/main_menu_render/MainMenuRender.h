//
// Created by vydra on 8/13/20.
//

#pragma once

#include "core/entities/render_entities/CleanerRender.h"
#include "core/entities/render_entities/IRender.h"
#include "core/entities/render_entities/TextPanelsRender.h"

class MainMenuRender : public IRender {
 private:
  unsigned SCREENMODE_X = 0;
  unsigned SCREENMODE_Y = 0;

  const char* question;
  const char** choices;
  unsigned count_choices;
  unsigned* highlighted_choice;

 public:
  explicit MainMenuRender(unsigned input_screen_x, unsigned input_screen_y, const char* input_question,
                          const char** input_choices, unsigned input_count_choices, unsigned* input_highlighted_choice);
  ~MainMenuRender() override;

  void render() override;
};
