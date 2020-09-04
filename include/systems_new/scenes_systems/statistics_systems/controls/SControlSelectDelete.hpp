//
// Created by vydra on 8/19/20.
//

#pragma once

#include "systems_new/IControl.h"
#include "systems_new/scenes_systems/statistics_systems/IStatisticsSystem.hpp"

class SControlSelectDelete : public IControl {
 private:
  IStatisticsSystem *score_system = nullptr;
  StringsListData *score_list_data = nullptr;

 public:
  explicit SControlSelectDelete(IStatisticsSystem *input_score_system, StringsListData *input_score_list_data)
      : IControl("SControlSelectDelete") {
    score_system = input_score_system;
    score_list_data = input_score_list_data;
  }
  ~SControlSelectDelete() override {
    score_system = nullptr;
  }

  void execute() override {
    score_system->free_file();
    score_list_data->set_records_count(0);
    score_list_data->set_pages_count(0);
    score_list_data->set_current_page(0);
  }
};
