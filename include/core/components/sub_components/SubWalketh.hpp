//
// Created by vydra on 8/7/20.
//

#pragma once

#include "SubLocatable.hpp"
#include "core/components/abs_components/AbsInteroperable.hpp"

class SubWalketh : protected AbsInteroperable, public SubLocatable {
 protected:
  void set_sight();

 public:
  explicit SubWalketh(unsigned input_x, unsigned input_y);
  ~SubWalketh();

  unsigned get_sight_x() const;
  unsigned get_sight_y() const;

  void go_up();
  void go_down(unsigned input_border);
  void go_left();
  void go_right(unsigned input_border);
};
