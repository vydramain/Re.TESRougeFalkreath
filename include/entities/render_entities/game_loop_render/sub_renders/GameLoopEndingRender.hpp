//
// Created by vydra on 8/18/20.
//

#pragma once

#include "entities/ParameterQueryData.hpp"
#include "entities/render_entities/IRender.h"
#include "entities/render_entities/TextPanelsRender.h"

class GameLoopEndingRender : public IRender {
 private:
  unsigned SCREENMODE_X = 0;
  unsigned SCREENMODE_Y = 0;

  ParameterQueryData *ending_data;

 public:
  explicit GameLoopEndingRender(ParameterQueryData *input_ending_data);
  ~GameLoopEndingRender() override;

  void update_fields(unsigned input_screen_x, unsigned input_screen_y);

  void render() override;
};