//
// Created by vydra on 8/19/20.
//

#pragma once

#include "systems/scenes_systems/game_loop_systems/controls/GLControlExit.h"
#include "systems/scenes_systems/game_loop_systems/controls/IGLControl.h"
#include "systems/scenes_systems/statistics_systems/IStatisticsSystem.hpp"
#include "systems/scenes_systems/statistics_systems/StdStatisticsSystem.hpp"

class GLControlScoreSave : public IGLControl {
 private:
  ParameterQueryDataSet *data = nullptr;
  IStatisticsSystem *score_system = nullptr;

 public:
  explicit GLControlScoreSave(IWorldSystem *input_world_system, ParameterQueryDataSet *input_ending_data)
      : IGLControl("GLControlScoreSave") {
    data = input_ending_data;
    score_system = new StdStatisticsSystem();
    score_system->set_location_system(input_world_system);
  }
  ~GLControlScoreSave() override {
    delete score_system;
  }

  IControl *get_last_executed_control() override {
    return new GLEControlSelectExit();
  }

  void execute() override {
    if (data->get_data(new std::string("statistic_data"))->get_highlighted() == 1) {
      score_system->add_score();
    }
  }
};
