//
// Created by vydra on 9/17/20.
//

#pragma once

#include "components/abs_components/AbsSentientCondition.hpp"

class SubSentientCondition : public AbsSentientCondition {
 public:
  explicit SubSentientCondition();
  explicit SubSentientCondition(condition input_condition);
  virtual ~SubSentientCondition();

  void set_walk();
  void set_fight();
  void set_pursue();
  void set_current_condition(condition input_condition);

  condition get_current_condition() const;
};
