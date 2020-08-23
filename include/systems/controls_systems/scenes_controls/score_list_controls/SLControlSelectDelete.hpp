//
// Created by vydra on 8/19/20.
//

#pragma once

#include "systems/controls_systems/IControl.h"
#include "systems/scenes_systems/score_systems/IScoreSystem.hpp"

class SLControlSelectDelete : public IControl {
 private:
  IScoreSystem *score_system = nullptr;
  ScoreListData *score_list_data = nullptr;

 public:
  explicit SLControlSelectDelete(IScoreSystem *input_score_system, ScoreListData *input_score_list_data)
      : IControl("SLControlSelectDelete") {
    score_system = input_score_system;
    score_list_data = input_score_list_data;
  }
  ~SLControlSelectDelete() override {
    score_system = nullptr;
  }

  void execute() override {
    score_system->free_file();
    score_list_data->set_records_count(0);
    score_list_data->set_pages_count(0);
    score_list_data->set_current_page(0);
  }
};
