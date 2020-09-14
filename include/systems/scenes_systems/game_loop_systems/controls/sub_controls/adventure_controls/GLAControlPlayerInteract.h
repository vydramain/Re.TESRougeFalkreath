//
// Created by vydra on 8/3/20.
//

#pragma once

#include <cstring>

#include "adds/log_systems/PseudoLogSystem.hpp"
#include "systems/IControl.h"
#include "systems/scenes_systems/game_loop_systems/actions/InteractAbilitySystem.hpp"
#include "systems/scenes_systems/game_loop_systems/world/IWorldSystem.hpp"

class GLAControlPlayerInteract : public IControl {
 private:
  InteractAbilitySystem* interact_ability_system = nullptr;
  IWorldSystem* world_system;

 public:
  explicit GLAControlPlayerInteract(IWorldSystem* input_location_system)
      : IControl("GLAControlPlayerInteract"),
        interact_ability_system(new InteractAbilitySystem()),
        world_system(input_location_system) {}
  ~GLAControlPlayerInteract() override {
    delete interact_ability_system;
    world_system = nullptr;
  }

  void execute() override {
    interact_ability_system->try_interact_with(world_system);
  }
};
