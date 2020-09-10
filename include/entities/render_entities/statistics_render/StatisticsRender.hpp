//
// Created by vydra on 8/19/20.
//

#pragma once

#include "./BearLibTerminal.h"
#include "entities/data_entities/StringsListData.hpp"
#include "entities/render_entities/CleanerRender.h"
#include "entities/render_entities/IRender.h"
#include "entities/render_entities/TextPanelsRender.h"

class StatisticsRender : public IRender {
 private:
  unsigned SCREENMODE_X = 0;
  unsigned SCREENMODE_Y = 0;

  unsigned records_count = 8;

  StringsListData*score_list_data = nullptr;

  void render_title();
  std::vector<std::string *> *create_records();
  void render_filled_list();
  void render_empty_list();

 public:
  explicit StatisticsRender(unsigned input_screen_x, unsigned input_screen_y, StringsListData* input_score_list_data);
  ~StatisticsRender() override;

  void render() override;
};