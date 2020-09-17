//
// Created by vydra on 9/17/20.
//

#pragma once

#include "entities/location_entities/sentients_entities/Sentient.h"
#include "systems/scenes_systems/game_loop_systems/world/IWorldSystem.hpp"
#include "systems/scenes_systems/game_loop_systems/world/sub_systems/ai_systems/IArctificialIntelligence.hpp"
#include "systems/scenes_systems/game_loop_systems/world/sub_systems/map_systems/entities_system/sub_systems/SentientsSystem.h"

class SentientsAISystem : public IArtificialIntelligence {
 private:
  IWorldSystem* current_world_system;
  SentientsSystem* current_sentient_system;

  void look_around(Sentient* input_sentient);
  void fight_player(Sentient* input_sentient);
  void pursue_player(Sentient* input_sentient);
  void walk(Sentient* input_sentient);

 public:
  explicit SentientsAISystem(IWorldSystem* input_world_system);
  virtual ~SentientsAISystem();

  void update() override;
};