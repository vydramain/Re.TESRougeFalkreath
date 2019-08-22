//
// Created by vydra on 8/22/19.
//

#include "inGameParts/logicComponents/items/septim.h"

septim::septim() : item(){
  price = 1;
}

septim::septim(unsigned Count) : item() {
  price = Count;
}

septim::septim(unsigned X, unsigned Y, playMap *AREA) : item(X,Y) {
  AREA->changeKnot3(X,Y, '$');
  price = 1;
}