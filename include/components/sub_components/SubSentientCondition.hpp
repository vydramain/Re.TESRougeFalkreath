//
// Created by vydra on 9/17/20.
//

#pragma once

#include "components/abs_components/AbsSentientCondition.hpp"

class SubSentientCondition : public AbsSentientCondition {
 public:
  explicit SubSentientCondition();
  virtual ~SubSentientCondition();

  void set_walk();
  void set_fight();
  void set_pursue();

  condition get_current_condition();
};
