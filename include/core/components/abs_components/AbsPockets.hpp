//
// Created by vydra on 8/7/20.
//

#pragma once

#include "core/entities/location_enities/items_entities/Item.h"

class AbsPockets {
 protected:
  Item** pocket;
  const unsigned pocket_size;
  unsigned wallet = 0;

  explicit AbsPockets(unsigned int input_pocket_size) : pocket_size(input_pocket_size) {
    pocket = new Item*[pocket_size];
    for (unsigned int i = 0; i < pocket_size; i++) {
      pocket[i] = nullptr;
    }
  }

  ~AbsPockets() {
    for (unsigned int i = 0; i < pocket_size; i++) {
      delete[] pocket[i];
    }
    delete[] pocket;
  }
};
