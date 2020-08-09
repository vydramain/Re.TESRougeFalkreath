//
// Created by vydra on 8/3/20.
//

#pragma once

#include <algorithm>
#include <vector>

#include "core/entities/location_enities/items_entities/Item.h"

class Items {
 private:
  std::vector<Item> vec_items;

 public:
  explicit Items(unsigned input_count);
  ~Items();

  void put_item(Item *input_item);
  Item *remove_item(unsigned input_index);

  unsigned get_size() const;
  int get_item_index(Item *input_item);
  int get_item_index(unsigned input_x, unsigned input_y);
  const Item *get_item(unsigned input_index) const;
};
