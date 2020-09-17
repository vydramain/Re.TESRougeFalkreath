//
// Created by vydra on 7/30/20.
//

#pragma once

#include "systems/IControl.h"
#include "systems/scenes_systems/game_loop_systems/actions/MoveAbilitySystem.hpp"

class GLAControlPlayerLeft : public IControl {
 private:
  IWorldSystem* world_system;

 public:
  explicit GLAControlPlayerLeft(IWorldSystem* input_world_system)
      : IControl("GLAControlPlayerLeft"), world_system(input_world_system) {}

  void execute() override {
    if (MoveAbilitySystem::can_move_to(
            world_system, world_system->get_current_map()->get_entities_system()->get_player()->get_current_x() - 1,
            world_system->get_current_map()->get_entities_system()->get_player()->get_current_y())) {
      world_system->get_current_map()->get_entities_system()->get_player()->go_left();
      if (world_system->get_current_map()->get_entities_system()->get_player()->get_steps_count() > 3000) {
        world_system->get_current_map()->get_entities_system()->get_player()->set_hp(0);
      }
    } else {
      world_system->get_current_map()->get_entities_system()->get_player()->look_left();
    }
  }
};
