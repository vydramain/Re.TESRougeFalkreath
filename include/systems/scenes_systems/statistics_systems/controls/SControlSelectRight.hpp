//
// Created by vydra on 8/19/20.
//

#pragma once

#include "systems/IControl.h"

class SControlSelectRight : public IControl {
 private:
  StringsListData *score_list_data = nullptr;

 public:
  explicit SControlSelectRight(StringsListData *input_score_list_data) : IControl("SControlSelectRight") {
    score_list_data = input_score_list_data;
  }
  ~SControlSelectRight() override {
    score_list_data = nullptr;
  };

  void execute() override {
    if (score_list_data->get_current_page() < score_list_data->get_pages_count()) {
      score_list_data->set_current_page(score_list_data->get_current_page() + 1);
    }
  }
};
