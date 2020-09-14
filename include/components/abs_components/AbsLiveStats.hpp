//
// Created by vydra on 9/14/20.
//

#pragma once

class AbsLiveStats {
 protected:
  enum status {
    NORMAL,
    TIRED,
    AT_DEATH,
    DEATH
  };

  unsigned hp;
  unsigned mp;
  unsigned ap;
  status current_status;
  };