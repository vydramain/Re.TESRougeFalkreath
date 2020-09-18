//
// Created by vydra on 9/17/20.
//

#include "components/sub_components/SubSentientCondition.hpp"

SubSentientCondition::SubSentientCondition() : AbsSentientCondition() {}

SubSentientCondition::SubSentientCondition(AbsSentientCondition::condition input_condition) : AbsSentientCondition() {
  current_condition = input_condition;
}

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

void SubSentientCondition::set_current_condition(AbsSentientCondition::condition input_condition) {
  current_condition = input_condition;
}

AbsSentientCondition::condition SubSentientCondition::get_current_condition() const {
  return current_condition;
}
