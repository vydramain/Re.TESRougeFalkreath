//
// Created by vydra on 8/3/20.
//

#ifndef INCLUDE_ECS_ENTITIES_ITEMS_ENTITIES_ITEM_H_
#define INCLUDE_ECS_ENTITIES_ITEMS_ENTITIES_ITEM_H_

class Item {
 private:
  const char* name;

 public:
  explicit Item(const char* input_name);
  ~Item();

  void set_name(const char* input_name);

  const char* get_name() const;
};

#endif  // INCLUDE_ECS_ENTITIES_ITEMS_ENTITIES_ITEM_H_
