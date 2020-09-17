//
// Created by vydra on 9/17/20.
//

#pragma once

class AbsSentientCondition {
 protected:
  enum condition {
    WALK,
    FIGHT,
    PURSUE
  };

  condition current_condition = WALK;
};
