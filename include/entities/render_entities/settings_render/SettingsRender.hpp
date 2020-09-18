//
// Created by vydra on 9/5/20.
//

#pragma once

#include "entities/render_entities/CleanerRender.h"
#include "entities/render_entities/IRender.h"
#include "entities/render_entities/TextPanelsRender.h"
#include "systems/launcher_system/data/ParameterQueryData.hpp"

class SettingsRender : public IRender {
 private:
  unsigned SCREENMODE_X = 0;
  unsigned SCREENMODE_Y = 0;

  ParameterQueryData *settings_data;

 public:
  explicit SettingsRender(unsigned input_screen_x, unsigned input_screen_y, ParameterQueryData *input_settings_data);
  ~SettingsRender() override;

  void render() override;
};
