//
// Created by vydra on 8/22/19.
//

#include "inGameParts/logicComponents/items/septim.h"

septim::septim() : item() {
  itemX_ = 0;
  itemY_ = 0;
  price = 1;
}

septim::septim(unsigned Count) : item() {
  itemX_ = 0;
  itemY_ = 0;
  price = Count;
}

septim::septim(unsigned X, unsigned Y, playMap* AREA) : item(X, Y) {
  itemX_ = X;
  itemY_ = Y;
  AREA->changeKnot3(X, Y, '$');
  price = 1;
}

bool septim::placeSeptim(unsigned X, unsigned Y, playMap* AREA) {
  itemX_ = X;
  itemY_ = Y;
  AREA->changeKnot3(X, Y, '$');
  return false;
}

bool septim::priceSeptim(unsigned Price) {
  price = Price;
  return false;
}
unsigned septim::conditionPriceSeptim() {
  return price;
}

unsigned septim::conditionPlaceSeptimX() {
  return itemX_;
}

unsigned septim::conditionPlaceSeptimY() {
  return itemY_;
}
