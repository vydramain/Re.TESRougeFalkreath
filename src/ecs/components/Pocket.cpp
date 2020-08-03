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
Item *Pocket::get_item(const unsigned int input_index) {
  Item *pointer = vec_items.data();
  return &pointer[input_index];
}
const Item *Pocket::get_item(const unsigned int input_index) const {
  const Item *pointer = vec_items.data();
  return &pointer[input_index];
}
void Pocket::clear_pocket() {
  vec_items.clear();
}
