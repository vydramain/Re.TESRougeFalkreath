//
// Created by vydra on 8/3/20.
//

#ifndef INCLUDE_ECS_COMPONENTS_POCKET_H_
#define INCLUDE_ECS_COMPONENTS_POCKET_H_

#include <vector>

#include "ecs/entities/items_entities/Item.h"

class Pocket {
 private:
  std::vector<Item> vec_items;

 public:
  explicit Pocket(unsigned input_count);
  ~Pocket();

  void put_item(Item input_item);
  Item *remove_item(unsigned input_index);

  unsigned get_size() const;
  Item *get_item(unsigned input_index);
  const Item *get_item(unsigned input_index) const;
};

#endif  // INCLUDE_ECS_COMPONENTS_POCKET_H_