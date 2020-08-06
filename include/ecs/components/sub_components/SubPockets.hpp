//
// Created by vydra on 8/7/20.
//

#pragma once

#include "ecs/components/abs_components/AbsPockets.hpp"

class SubPockets : protected AbsPockets {
 public:
  explicit SubPockets(unsigned input_pocket_size);
  ~SubPockets();

  bool put_item(Item *input_item);
  Item *remove_item(unsigned input_index);

  void set_wallet(unsigned input_wallet);

  unsigned get_pocket_size() const;
  int get_item_index(Item *input_item);
  int get_item_index(unsigned input_x, unsigned input_y);
  const Item *get_item(unsigned input_index) const;
  void clear_pocket();
  unsigned get_wallet() const;
};
