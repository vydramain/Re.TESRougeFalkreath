//
// Created by vydra on 8/19/20.
//

#pragma once

#include "systems/controls_systems/IControl.h"

class SLControlSelectLeft : public IControl {
 private:
  ScoreListData *score_list_data = nullptr;

 public:
  explicit SLControlSelectLeft(ScoreListData *input_score_list_data) : IControl("SLControlSelectLeft") {
    score_list_data = input_score_list_data;
  }
  ~SLControlSelectLeft() override {
    score_list_data = nullptr;
  }

  void execute() override {
    if (score_list_data->get_current_page() > 0) {
      score_list_data->set_current_page(score_list_data->get_current_page() - 1);
    }
  }
};
