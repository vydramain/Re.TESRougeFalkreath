//
// Created by vydra on 8/7/20.
//

#pragma once

#include "components/abs_components/AbsInteroperable.hpp"
#include "components/abs_components/AbsStepsCount.hpp"
#include "components/sub_components/SubLocatable.hpp"

class SubWalketh : protected AbsInteroperable, protected AbsStepsCount, public SubLocatable {
 protected:
  void set_sight();

 public:
  explicit SubWalketh(unsigned input_x, unsigned input_y);
  ~SubWalketh();

  unsigned get_sight_x() const;
  unsigned get_sight_y() const;

  unsigned get_steps_count() const;

  void go_up();
  void go_down(unsigned input_border);
  void go_left();
  void go_right(unsigned input_border);

  void look_up();
  void look_down();
  void look_left();
  void look_right();
};
