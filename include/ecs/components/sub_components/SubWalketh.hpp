//
// Created by vydra on 8/7/20.
//

#pragma once

#include "ecs/components/abs_components/AbsInteroperable.hpp"
#include "ecs/components/abs_components/AbsLocatable.hpp"

class SubWalketh : public AbsLocatable, AbsInteroperable {
 private:
  void set_sight();

 public:
  explicit SubWalketh(unsigned input_x, unsigned input_y);
  ~SubWalketh();

  void go_up();
  void go_down(unsigned input_border);
  void go_left();
  void go_right(unsigned input_border);
};
