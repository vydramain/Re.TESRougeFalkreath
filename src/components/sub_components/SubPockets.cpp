//
// Created by vydra on 8/7/20.
//

#include "components/sub_components/SubPockets.hpp"

SubPockets::SubPockets(unsigned int input_pocket_size) : AbsPockets(input_pocket_size) {}

SubPockets::~SubPockets() = default;

Item *SubPockets::remove_item(unsigned int input_index) {
  auto *item = pocket[input_index];
  pocket[input_index] = nullptr;
  return item;
}

bool SubPockets::put_item(Item *input_item) {
  for (unsigned int i = 0; i < pocket_size; i++) {
    if (pocket[i] == nullptr) {
      pocket[i] = input_item;
      return true;
    }
  }
  return false;
}

unsigned int SubPockets::get_wallet() const {
  return wallet;
}

void SubPockets::set_wallet(unsigned int input_wallet) {
  wallet = input_wallet;
}

unsigned int SubPockets::get_pocket_size() const {
  return pocket_size;
}

int SubPockets::get_item_index(Item *input_item) {
  for (unsigned int i = 0; i < pocket_size; i++) {
    if (*pocket[i] == *input_item) {
      return i;
    }
  }
  return -1;
}

int SubPockets::get_item_index(unsigned int input_x, unsigned int input_y) {
  for (unsigned int i = 0; i < pocket_size; i++) {
    if (pocket[i]->get_current_x() == input_x && pocket[i]->get_current_y() == input_y) {
      return i;
    }
  }
  return -1;
}

const Item *SubPockets::get_item(unsigned int input_index) const {
  const auto *item = pocket[input_index];
  return item;
}

void SubPockets::clear_pocket() {
  for (unsigned int i = 0; i < pocket_size; i++) {
    delete pocket[i];
    pocket[i] = nullptr;
  }
}
