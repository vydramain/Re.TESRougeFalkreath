//
// Created by vydra on 9/17/20.
//

#include "systems/scenes_systems/game_loop_systems/world/sub_systems/ai_systems/sentients_ai_system/SentientsAISystem.hpp"

void SentientsAISystem::look_around(Sentient* input_sentient) {
  if ((((current_world_system->get_current_map()->get_entities_system()->get_player()->get_current_x() ==
             input_sentient->get_current_x() - 1 ||
         current_world_system->get_current_map()->get_entities_system()->get_player()->get_current_x() ==
             input_sentient->get_current_x() + 1) &&
        current_world_system->get_current_map()->get_entities_system()->get_player()->get_current_y() ==
            input_sentient->get_current_y())) ||
      ((((current_world_system->get_current_map()->get_entities_system()->get_player()->get_current_y() ==
              input_sentient->get_current_y() - 1 ||
          current_world_system->get_current_map()->get_entities_system()->get_player()->get_current_y() ==
              input_sentient->get_current_y() + 1) &&
         current_world_system->get_current_map()->get_entities_system()->get_player()->get_current_x() ==
             input_sentient->get_current_x())))) {
    input_sentient->set_fight();
    current_world_system->get_current_map()->get_entities_system()->get_player()->set_fight();
    input_sentient->set_pseudo_color(0x99ff0000);
    return;
  }
  if (current_world_system->get_current_map()->get_entities_system()->get_player()->get_current_x() >=
          input_sentient->get_current_x() - 8 &&
      current_world_system->get_current_map()->get_entities_system()->get_player()->get_current_x() <=
          input_sentient->get_current_x() + 8 &&
      current_world_system->get_current_map()->get_entities_system()->get_player()->get_current_y() >=
          input_sentient->get_current_y() - 8 &&
      current_world_system->get_current_map()->get_entities_system()->get_player()->get_current_y() <=
          input_sentient->get_current_y() + 8) {
    input_sentient->set_pursue();
    input_sentient->set_pseudo_color(0x99ff0000);
    return;
  }
  input_sentient->set_walk();
  input_sentient->set_pseudo_color(0xffffffff);
}

void SentientsAISystem::fight_player(Sentient* input_sentient) {
  srand48(time(nullptr));
  unsigned temp_rand = rand() % 4 + 2;
  current_world_system->get_current_map()->get_entities_system()->get_player()->take_damage(
      current_world_system->get_current_map()->get_entities_system()->get_player()->get_hp() / temp_rand);
}

void SentientsAISystem::pursue_player(Sentient* input_sentient) {
  srand48(time(nullptr));
  unsigned temp_rand = rand() % 10;
  if (temp_rand < 9) {
    unsigned new_x = input_sentient->get_current_x();
    unsigned new_y = input_sentient->get_current_y();
    if (current_world_system->get_current_map()->get_entities_system()->get_player()->get_current_x() > new_x + 1 &&
        MoveAbilitySystem::can_move_to(current_world_system, new_x + 1, new_y)) {
      input_sentient->go_right(current_world_system->get_current_map()->get_size_x());
      return;
    }
    if (current_world_system->get_current_map()->get_entities_system()->get_player()->get_current_x() < new_x - 1 &&
        MoveAbilitySystem::can_move_to(current_world_system, new_x - 1, new_y)) {
      input_sentient->go_left();
      return;
    }
    if (current_world_system->get_current_map()->get_entities_system()->get_player()->get_current_y() > new_y + 1 &&
        MoveAbilitySystem::can_move_to(current_world_system, new_x, new_y + 1)) {
      input_sentient->go_down(current_world_system->get_current_map()->get_size_y());
      return;
    }
    if (current_world_system->get_current_map()->get_entities_system()->get_player()->get_current_y() < new_y - 1 &&
        MoveAbilitySystem::can_move_to(current_world_system, new_x, new_y - 1)) {
      input_sentient->go_up();
      return;
    }
  }
}

void SentientsAISystem::walk(Sentient* input_sentient) {
  srand48(time(nullptr));
  unsigned temp_rand = rand() % 10;
  if (temp_rand == 9 && MoveAbilitySystem::can_move_to(current_world_system, input_sentient->get_current_x() - 1,
                                                       input_sentient->get_current_y())) {
    input_sentient->go_left();
    return;
  }
  if (temp_rand == 8 && MoveAbilitySystem::can_move_to(current_world_system, input_sentient->get_current_x() + 1,
                                                       input_sentient->get_current_y())) {
    input_sentient->go_right(current_world_system->get_current_map()->get_size_x());
    return;
  }
  if (temp_rand == 7 && MoveAbilitySystem::can_move_to(current_world_system, input_sentient->get_current_x(),
                                                       input_sentient->get_current_y() - 1)) {
    input_sentient->go_up();
    return;
  }
  if (temp_rand == 6 && MoveAbilitySystem::can_move_to(current_world_system, input_sentient->get_current_x(),
                                                       input_sentient->get_current_y() + 1)) {
    input_sentient->go_down(current_world_system->get_current_map()->get_size_y());
    return;
  }
}

SentientsAISystem::SentientsAISystem(IWorldSystem* input_world_system) {
  current_world_system = input_world_system;
}

SentientsAISystem::~SentientsAISystem() = default;

void SentientsAISystem::update() {
  for (unsigned i = 1; i < current_world_system->get_current_map()->get_entities_system()->get_sentients_size(); i++) {
    if (current_world_system->get_current_map()->get_entities_system()->get_sentient(i)->get_status() !=
        AbsLiveStats::DEATH) {
      look_around(current_world_system->get_current_map()->get_entities_system()->get_sentient(i));
      if (current_world_system->get_current_map()->get_entities_system()->get_sentient(i)->get_current_condition() ==
          AbsSentientCondition::WALK) {
        walk(current_world_system->get_current_map()->get_entities_system()->get_sentient(i));
      }
      if (current_world_system->get_current_map()->get_entities_system()->get_sentient(i)->get_current_condition() ==
          AbsSentientCondition::PURSUE) {
        pursue_player(current_world_system->get_current_map()->get_entities_system()->get_sentient(i));
      }
      if (current_world_system->get_current_map()->get_entities_system()->get_sentient(i)->get_current_condition() ==
          AbsSentientCondition::FIGHT) {
        fight_player(current_world_system->get_current_map()->get_entities_system()->get_sentient(i));
      }
    }
  }
}
