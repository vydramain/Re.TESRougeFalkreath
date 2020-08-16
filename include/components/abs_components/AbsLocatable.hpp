//
// Created by vydra on 8/7/20.
//

#pragma once

class AbsLocatable {
 protected:
  unsigned current_x;
  unsigned current_y;

  explicit AbsLocatable(const unsigned input_x, const unsigned input_y) {
    current_x = input_x;
    current_y = input_y;
  }
  ~AbsLocatable() = default;
};
