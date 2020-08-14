//
// Created by vydra on 8/14/20.
//

#pragma once

#include "core/components/abs_components/AbsFloor.hpp"

class SubFloor : public AbsFloor {
 public:
  explicit SubFloor(bool input_floor = false);
  ~SubFloor();

  void set_floor(bool input_floor);
  bool get_floor() const;
};