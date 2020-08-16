//
// Created by vydra on 8/14/20.
//

#pragma once

#include "entities/location_entities/items_entities/Item.h"

class Coin : public Item {
 public:
  explicit Coin(unsigned input_x, unsigned input_y);
  ~Coin() override;
};
