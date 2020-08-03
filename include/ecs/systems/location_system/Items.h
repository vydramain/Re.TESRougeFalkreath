//
// Created by vydra on 8/3/20.
//

#ifndef INCLUDE_ECS_SYSTEMS_LOCATION_SYSTEM_ITEMS_H_
#define INCLUDE_ECS_SYSTEMS_LOCATION_SYSTEM_ITEMS_H_

#include <vector>

#include "ecs/entities/items_entities/Item.h"

class Items {
 private:
  std::vector<Item> vec_items;

 public:
  explicit Items(unsigned input_count);
  ~Items();

  void put_item(Item input_item);
  Item *remove_item(unsigned input_index);

  unsigned get_size() const;
  Item *get_item(unsigned input_index);
  const Item *get_item(unsigned input_index) const;
};

#endif  // INCLUDE_ECS_SYSTEMS_LOCATION_SYSTEM_ITEMS_H_
