//
// Created by vydra on 8/19/20.
//

#pragma once

#include "systems_new/IControl.h"

class SControlSelectLeft : public IControl {
 private:
  StringsListData *score_list_data = nullptr;

 public:
  explicit SControlSelectLeft(StringsListData *input_score_list_data) : IControl("SControlSelectLeft") {
    score_list_data = input_score_list_data;
  }
  ~SControlSelectLeft() override {
    score_list_data = nullptr;
  }

  void execute() override {
    if (score_list_data->get_current_page() > 0) {
      score_list_data->set_current_page(score_list_data->get_current_page() - 1);
    }
  }
};
