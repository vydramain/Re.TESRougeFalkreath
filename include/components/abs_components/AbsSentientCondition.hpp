//
// Created by vydra on 9/17/20.
//

#pragma once

class AbsSentientCondition {
 public:
  enum condition {
    WALK,
    FIGHT,
    PURSUE
  };

 protected:
  condition current_condition = WALK;
};
