//
// Created by vydra on 8/3/20.
//

#pragma once

#include <algorithm>
#include <vector>

#include "core/entities/location_enities/items_entities/Item.h"

class ItemsSystem {
 private:
  std::vector<Item*> items;

 public:
  explicit ItemsSystem(unsigned input_count);
  ~ItemsSystem();

  void put_item(Item *input_item);
  Item *remove_item(unsigned input_index);

  unsigned get_size() const;
  int get_item_index(Item *input_item);
  int get_item_index(unsigned input_x, unsigned input_y);
  const Item *get_item(unsigned input_index) const;
};
