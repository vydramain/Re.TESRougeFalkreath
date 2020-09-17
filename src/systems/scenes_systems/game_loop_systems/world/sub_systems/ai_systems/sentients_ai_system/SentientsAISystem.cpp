//
// Created by vydra on 9/17/20.
//

#include "systems/scenes_systems/game_loop_systems/world/sub_systems/ai_systems/sentients_ai_system/SentientsAISystem.hpp"

void SentientsAISystem::look_around(Sentient* input_sentient) {
  if (current_sentient_system->get_player()->get_current_x() <= input_sentient->get_current_x() + 5 &&
      current_sentient_system->get_player()->get_current_x() >= input_sentient->get_current_x() - 5 &&
      current_sentient_system->get_player()->get_current_y() <= input_sentient->get_current_y() + 5 &&
      current_sentient_system->get_player()->get_current_y() >= input_sentient->get_current_y() - 5) {
    input_sentient->set_pursue();
    return;
  }
  if ((current_sentient_system->get_player()->get_current_x() <= input_sentient->get_current_x() + 1 &&
       current_sentient_system->get_player()->get_current_x() >= input_sentient->get_current_x() - 1) ||
      (current_sentient_system->get_player()->get_current_y() <= input_sentient->get_current_y() + 1 &&
       current_sentient_system->get_player()->get_current_y() >= input_sentient->get_current_y() - 1)) {
    input_sentient->set_fight();
    return;
  }
  input_sentient->set_walk();
}

void SentientsAISystem::fight_player(Sentient* input_sentient) {}

void SentientsAISystem::pursue_player(Sentient* input_sentient) {
  srand48(time(nullptr));
  unsigned temp_rand = rand() % 10;
  if (temp_rand < 7) {
    if (current_sentient_system->get_player()->get_current_x() > input_sentient->get_current_x() + 1) {
      input_sentient->go_left();
    }
    if (current_sentient_system->get_player()->get_current_x() < input_sentient->get_current_x() - 1) {
      input_sentient->go_right(current_world_system->get_current_map()->get_size_x());
    }
    if (current_sentient_system->get_player()->get_current_y() > input_sentient->get_current_y() + 1) {
      input_sentient->go_up();
    }
    if (current_sentient_system->get_player()->get_current_y() < input_sentient->get_current_y() - 1) {
      input_sentient->go_down(current_world_system->get_current_map()->get_size_y());
    }
  }
}

void SentientsAISystem::walk(Sentient* input_sentient) {
  srand48(time(nullptr));
  unsigned temp_rand = rand() % 10;
  if (temp_rand > 7) {
    input_sentient->go_left();
  }
  if (temp_rand < 8 && temp_rand > 5) {
    input_sentient->go_right(current_world_system->get_current_map()->get_size_x());
  }
  if (temp_rand < 6 && temp_rand > 3) {
    input_sentient->go_up();
  }
  if (temp_rand < 4 && temp_rand > 1) {
    input_sentient->go_down(current_world_system->get_current_map()->get_size_y());
  }
}

SentientsAISystem::SentientsAISystem(IWorldSystem* input_world_system) {
  current_world_system = input_world_system;
  current_sentient_system = input_world_system->get_current_map()->get_entities_system();
}

SentientsAISystem::~SentientsAISystem() = default;

void SentientsAISystem::update() {
  for (unsigned i = 1; i < current_sentient_system->get_sentients_size(); i++) {
    look_around(current_sentient_system->get_sentient(i));
    if (current_sentient_system->get_sentient(i)->get_current_condition() == AbsSentientCondition::WALK) {
      walk(current_sentient_system->get_sentient(i));
    }
    if (current_sentient_system->get_sentient(i)->get_current_condition() == AbsSentientCondition::PURSUE) {
      pursue_player(current_sentient_system->get_sentient(i));
    }
    if (current_sentient_system->get_sentient(i)->get_current_condition() == AbsSentientCondition::FIGHT) {
      fight_player(current_sentient_system->get_sentient(i));
    }
  }
}
