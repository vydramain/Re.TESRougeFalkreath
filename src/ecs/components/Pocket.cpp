//
// Created by vydra on 8/3/20.
//

#include "ecs/components/Pocket.h"

Pocket::Pocket(unsigned input_count) {
  vec_items.reserve(input_count);
}

Pocket::Pocket(const Pocket &input_pocket) {
  vec_items.clear();
  for (auto &vec_item : input_pocket.vec_items) {
    vec_items.push_back(vec_item);
  }
}
Pocket::Pocket(Pocket &&input_pocket) noexcept {
  vec_items.clear();
  for (auto &vec_item : input_pocket.vec_items) {
    vec_items.push_back(vec_item);
  }
  input_pocket.vec_items.clear();
}
Pocket &Pocket::operator=(const Pocket &input_pocket) {
  vec_items.clear();
  for (auto &vec_item : input_pocket.vec_items) {
    vec_items.push_back(vec_item);
  }
  return *this;
}
Pocket &Pocket::operator=(Pocket &&input_pocket) noexcept {
  vec_items.clear();
  for (auto &vec_item : input_pocket.vec_items) {
    vec_items.push_back(vec_item);
  }
  input_pocket.vec_items.clear();
  return *this;
}

Pocket::~Pocket() {
  vec_items.clear();
}

void Pocket::put_item(Item input_item) {
  input_item.pick_up();
  vec_items.push_back(input_item);
}

Item *Pocket::remove_item(unsigned int input_index) {
  Item *pointer = vec_items.data();
  auto *returning_item = new Item(pointer[input_index]);
  vec_items.erase(vec_items.begin() + input_index);
  return returning_item;
}

unsigned Pocket::get_pocket_size() const {
  return vec_items.size();
}
int Pocket::get_item_index(Item *input_item) {
  auto it = std::find(vec_items.begin(), vec_items.end(), *input_item);
  if (it != vec_items.end()) {
    return std::distance(vec_items.begin(), it);
  }
  return -1;
}

int Pocket::get_item_index(unsigned int input_x, unsigned int input_y) {
  for (auto &vec_item : vec_items) {
    if (vec_item.get_current_x() == input_x && vec_item.get_current_y() == input_y) {
      auto it = std::find(vec_items.begin(), vec_items.end(), vec_item);
      return std::distance(vec_items.begin(), it);
    }
  }
  return -1;
}

const Item *Pocket::get_item(unsigned int input_index) const {
  const Item *pointer = vec_items.data();
  return &pointer[input_index];
}

void Pocket::clear_pocket() {
  vec_items.clear();
}
