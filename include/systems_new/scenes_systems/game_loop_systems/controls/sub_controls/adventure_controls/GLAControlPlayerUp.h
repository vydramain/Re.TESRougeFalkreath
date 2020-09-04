//
// Created by vydra on 7/30/20.
//

#pragma once

#include "systems/scenes_systems/game_loop_systems/location_systems/LocationSystem.h"
#include "systems_new/IControl.h"
#include "systems_new/scenes_systems/game_loop_systems/actions/MoveAbilitySystem.hpp"

class GLAControlPlayerUp : public IControl {
 private:
  IWorldSystem* world_system;

 public:
  explicit GLAControlPlayerUp(IWorldSystem* input_world_system)
      : IControl("GLAControlPlayerUp"), world_system(input_world_system) {}

  void execute() override {
    if (MoveAbilitySystem::can_move_to(
            world_system, world_system->get_current_map()->get_entities_system()->get_player()->get_current_x(),
            world_system->get_current_map()->get_entities_system()->get_player()->get_current_y() - 1)) {
      world_system->get_current_map()->get_entities_system()->get_player()->go_up();
    } else {
      world_system->get_current_map()->get_entities_system()->get_player()->look_up();
    }
  }
};
