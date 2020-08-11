//
// Created by vydra on 8/3/20.
//

#pragma once

#include <algorithm>
#include <vector>

#include "core/entities/location_enities/items_entities/Item.h"

class ItemsSystem {
 protected:
  std::vector<Item*> items;

 public:
  explicit ItemsSystem();
  virtual ~ItemsSystem();

  virtual unsigned get_items_size() const;
  int get_item_index(Item *input_item);
  int get_item_index(unsigned input_x, unsigned input_y);
  const Item *get_item(unsigned input_index) const;

 protected:
  virtual void put_item(Item *input_item);
  virtual Item *remove_item(unsigned input_index);
};
