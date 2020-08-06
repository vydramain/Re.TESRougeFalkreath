//
// Created by vydra on 8/3/20.
//

#pragma once

#include "ecs/components/sub_components/SubPickable.hpp"

class Item : public SubPickable {
 private:
  const char* name;

 public:
  explicit Item(const char* input_name, bool input_pick, unsigned input_x, unsigned input_y);
  ~Item();

  bool operator==(const Item& rhs) const;
  bool operator!=(const Item& rhs) const;

  const char* get_name() const;
  void set_name(const char* input_name);
};
