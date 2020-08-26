//
// Created by vydra on 8/25/20.
//

#pragma once

class InteractAbilityData {
 private:
  int item_index = -1;
  int ambient_index = -1;

 public:
  void set_item_index(int input_index);
  void set_ambient_index(int input_index);

  int get_item_index() const;
  int get_ambient_index() const;
};
