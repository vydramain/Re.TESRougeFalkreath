//
// Created by vydra on 8/14/20.
//

#pragma once

class AbsFloor {
 protected:
  bool is_floor;

  explicit AbsFloor(bool input_floor) {
    is_floor = input_floor;
  }
  ~AbsFloor() = default;
};
