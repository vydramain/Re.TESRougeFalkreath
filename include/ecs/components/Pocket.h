//
// Created by vydra on 8/3/20.
//

#ifndef INCLUDE_ECS_COMPONENTS_POCKET_H_
#define INCLUDE_ECS_COMPONENTS_POCKET_H_

#include <algorithm>
#include <vector>

#include "ecs/entities/items_entities/Item.h"

class Pocket {
 private:
  std::vector<Item> vec_items;

 public:
  explicit Pocket(unsigned input_count);
  Pocket(const Pocket &input_pocket);
  Pocket(Pocket &&input_pocket) noexcept;
  Pocket &operator=(const Pocket &input_pocket);
  Pocket &operator=(Pocket &&input_pocket) noexcept;
  ~Pocket();

  void put_item(Item input_item);
  Item *remove_item(unsigned input_index);

  unsigned get_pocket_size() const;
  int get_item_index(Item *input_item);
  int get_item_index(unsigned input_x, unsigned input_y);
  const Item *get_item(unsigned input_index) const;
  void clear_pocket();
};

#endif  // INCLUDE_ECS_COMPONENTS_POCKET_H_
