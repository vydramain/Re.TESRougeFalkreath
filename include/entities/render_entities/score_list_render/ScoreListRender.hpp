//
// Created by vydra on 8/19/20.
//

#pragma once

#include "./BearLibTerminal.h"
#include "entities/StringsListData.hpp"
#include "entities/render_entities/CleanerRender.h"
#include "entities/render_entities/IRender.h"
#include "entities/render_entities/TextPanelsRender.h"

class ScoreListRender : public IRender {
 private:
  unsigned SCREENMODE_X = 0;
  unsigned SCREENMODE_Y = 0;

  StringsListData*score_list_data = nullptr;

 public:
  explicit ScoreListRender(unsigned input_screen_x, unsigned input_screen_y, StringsListData* input_score_list_data);
  ~ScoreListRender() override;

  void render() override;
};