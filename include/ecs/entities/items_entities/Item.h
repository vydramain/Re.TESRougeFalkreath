//
// Created by vydra on 8/3/20.
//

#ifndef INCLUDE_ECS_ENTITIES_ITEMS_ENTITIES_ITEM_H_
#define INCLUDE_ECS_ENTITIES_ITEMS_ENTITIES_ITEM_H_

#include "ecs/components/Pickable.h"

class Item : public Pickable {
 private:
  const char* name;

 public:
  explicit Item(const char* input_name, bool input_pick, unsigned input_x, unsigned input_y);
  Item(const Item& input_item);
  ~Item();

  bool operator==(const Item& rhs) const;
  bool operator!=(const Item& rhs) const;

  void set_name(const char* input_name);

  const char* get_name() const;
};

#endif  // INCLUDE_ECS_ENTITIES_ITEMS_ENTITIES_ITEM_H_
