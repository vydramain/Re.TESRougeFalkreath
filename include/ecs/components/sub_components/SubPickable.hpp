//
// Created by vydra on 8/7/20.
//

#pragma once

#include "ecs/components/abstract_components/AbsPickable.hpp"
#include "ecs/components/sub_components/SubLocatable.hpp"

class SubPickable : public AbsPickable, SubLocatable {
 public:
  explicit SubPickable(bool input_pick = false, unsigned input_x = 0, unsigned input_y = 0);
  ~SubPickable();

  void ejected(unsigned input_x, unsigned input_y);
  void picked_up();
  bool has_pick_up() const;
};
