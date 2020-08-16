//
// Created by vydra on 8/7/20.
//

#pragma once

#include "SubLocatable.hpp"
#include "components/abs_components/AbsPickable.hpp"

class SubPickable : protected AbsPickable, public SubLocatable {
 public:
  explicit SubPickable(bool input_pick = false, unsigned input_x = 0, unsigned input_y = 0);
  ~SubPickable();

  void ejected(unsigned input_x, unsigned input_y);
  void picked_up();
  bool has_pick_up() const;
};
