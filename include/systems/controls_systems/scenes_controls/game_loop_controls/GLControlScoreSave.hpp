//
// Created by vydra on 8/19/20.
//

#pragma once

#include "systems/controls_systems/scenes_controls/game_loop_controls/GLControlExit.h"
#include "systems/controls_systems/scenes_controls/game_loop_controls/IGLControl.h"
#include "systems/scenes_systems/game_loop_systems/location_systems/ILocationSystem.h"
#include "systems_new/scenes_systems/statistics_systems/IStatisticsSystem.hpp"
#include "systems_new/scenes_systems/statistics_systems/StdStatisticsSystem.hpp"

class GLControlScoreSave : public IGLControl {
 private:
  ParameterQueryData *ending_data = nullptr;
  IStatisticsSystem *score_system = nullptr;

 public:
  explicit GLControlScoreSave(ILocationSystem *input_location_system, ParameterQueryData *input_ending_data)
      : IGLControl("GLControlScoreSave") {
    ending_data = input_ending_data;
    score_system = new StdStatisticsSystem();
    score_system->set_location_system(input_location_system);
  }
  ~GLControlScoreSave() override {
    delete score_system;
  }

  IControl *get_last_executed_control() override {
    return new GLEControlSelectExit();
  }

  void execute() override {
    if (ending_data->get_highlighted() == 1) {
      score_system->add_score();
    }
  }
};
