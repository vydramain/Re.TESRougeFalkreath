//
// Created by vydra on 9/17/20.
//

#include "components/sub_components/SubSentientCondition.hpp"

SubSentientCondition::SubSentientCondition() : AbsSentientCondition() {}

SubSentientCondition::~SubSentientCondition() = default;

void SubSentientCondition::set_walk() {
  current_condition = WALK;
}

void SubSentientCondition::set_fight() {
  current_condition = FIGHT;
}

void SubSentientCondition::set_pursue() {
  current_condition = PURSUE;
}

AbsSentientCondition::condition SubSentientCondition::get_current_condition() {
  return current_condition;
}
