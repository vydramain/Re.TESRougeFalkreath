//
// Created by vydra on 8/13/20.
//

#pragma once

#include "entities/MenuData.hpp"
#include "entities/render_entities/CleanerRender.h"
#include "entities/render_entities/IRender.h"
#include "entities/render_entities/TextPanelsRender.h"

class MainMenuRender : public IRender {
 private:
  unsigned SCREENMODE_X = 0;
  unsigned SCREENMODE_Y = 0;

  MenuData *menu_data;

 public:
  explicit MainMenuRender(unsigned input_screen_x, unsigned input_screen_y, MenuData *input_menu_data);
  ~MainMenuRender() override;

  void render() override;
};
