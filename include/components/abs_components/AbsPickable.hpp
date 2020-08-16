//
// Created by vydra on 8/7/20.
//

#pragma once

class AbsPickable {
 protected:
  bool is_picked_up;

  explicit AbsPickable(const bool has_picked_up) {
    is_picked_up = has_picked_up;
  }

  ~AbsPickable() = default;
};
