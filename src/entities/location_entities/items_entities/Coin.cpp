//
// Created by vydra on 8/14/20.
//

#include "entities/location_entities/items_entities/Coin.h"

Coin::Coin(unsigned input_x, unsigned input_y) :
      Item("Coin", new PseudoRenderData("$", 0xddFFEB00), new GraficRenderData(0), input_x, input_y) {}

Coin::~Coin() = default;
