//
// Created by vydra on 9/14/20.
//

#pragma once

class AbsLiveStats {
 public:
  enum status { NORMAL, TIRED, AT_DEATH, DEATH };

 protected:
  unsigned hp;
  unsigned mp;
  unsigned ap;
  status current_status;
};