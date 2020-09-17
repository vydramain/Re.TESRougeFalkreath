//
// Created by vydra on 7/30/20.
//

#pragma once

#include "systems/IControl.h"
#include "systems/scenes_systems/game_loop_systems/actions/MoveAbilitySystem.hpp"
#include "systems/scenes_systems/game_loop_systems/world/IWorldSystem.hpp"

class GLAControlPlayerDown : public IControl {
 private:
  IWorldSystem* world_system;

 public:
  explicit GLAControlPlayerDown(IWorldSystem* input_world_system)
      : IControl("GLAControlPlayerDown"), world_system(input_world_system) {}

  void execute() override {
    if (MoveAbilitySystem::can_move_to(
            world_system, world_system->get_current_map()->get_entities_system()->get_player()->get_current_x(),
            world_system->get_current_map()->get_entities_system()->get_player()->get_current_y() + 1)) {
      world_system->get_current_map()->get_entities_system()->get_player()->go_down(
          world_system->get_current_map()->get_size_y());
      if (world_system->get_current_map()->get_entities_system()->get_player()->get_steps_count() > 3000) {
        world_system->get_current_map()->get_entities_system()->get_player()->set_hp(0);
      }
    } else {
      world_system->get_current_map()->get_entities_system()->get_player()->look_down();
    }
  }
};
