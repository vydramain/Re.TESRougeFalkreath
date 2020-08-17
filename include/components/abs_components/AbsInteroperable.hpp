//
// Created by vydra on 8/7/20.
//

#pragma once

class AbsInteroperable {
 protected:
  enum direction {
    DIRECTION_UP,
    DIRECTION_DOWN,
    DIRECTION_RIGHT,
    DIRECTION_LEFT,
  };

  unsigned sight_x = 0;
  unsigned sight_y = 0;
  direction current_direction = DIRECTION_LEFT;
};
