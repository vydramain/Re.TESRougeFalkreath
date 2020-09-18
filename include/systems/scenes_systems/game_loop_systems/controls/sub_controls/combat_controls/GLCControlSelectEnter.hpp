//
// Created by vydra on 9/15/20.
//

#pragma once

#include "systems/IControl.h"
#include "systems/scenes_systems/game_loop_systems/world/IWorldSystem.hpp"

class GLCControlSelectEnter : public IControl {
 private:
  IWorldSystem* world_system;
  ParameterQueryData* data;

 public:
  GLCControlSelectEnter(IWorldSystem* input_world_system, ParameterQueryData* input_data)
      : IControl("GLCControlSelectEnter") {
    world_system = input_world_system;
    data = input_data;
  }

  void execute() override {
    Sentient* opponent = nullptr;
    for (unsigned i = 1; i < world_system->get_current_map()->get_entities_system()->get_sentients_size(); i++) {
      if (world_system->get_current_map()->get_entities_system()->get_sentient(i)->get_current_condition() ==
          AbsSentientCondition::FIGHT) {
        opponent = world_system->get_current_map()->get_entities_system()->get_sentient(i);
      }
      break;
    }
    if (data->get_highlighted() == 1) {
      srand48(time(nullptr));
      unsigned temp_rand = rand() % 4 + 1;
      opponent->take_damage(opponent->get_hp() / temp_rand);
      if(opponent->get_status() == AbsLiveStats::DEATH){
        opponent->set_pseudo_color(0x66ffffff);
      }
    }
    if (data->get_highlighted() == 2 || opponent->get_status() == AbsLiveStats::DEATH) {
      opponent->set_current_condition(AbsSentientCondition::PURSUE);
      world_system->get_current_map()->get_entities_system()->get_player()->set_current_condition(
          AbsSentientCondition::WALK);
    }
  }
};
