//
// Created by vydra on 8/14/20.
//

#include "core/entities/location_enities/items_entities/Coin.h"

Coin::Coin(unsigned input_x, unsigned input_y) :
      Item("Coin", "$", 0xddFFEB00, input_x, input_y) {}

Coin::~Coin() = default;
