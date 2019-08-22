//
// Created by vydra on 8/22/19.
//

#ifndef TESROUGEFALKREATH_SEPTIM_H
#define TESROUGEFALKREATH_SEPTIM_H

#include <controlComponents/playMap.h>
#include "inGameParts/logicComponents/item.h"

class septim : public item {
 private:
  unsigned price;
 public:
  septim();
  septim(unsigned Count);
  septim(unsigned X, unsigned Y, playMap *AREA);
  ~septim() {}

  bool placeSeptim(unsigned X, unsigned Y, playMap *AREA);
  bool priceSeptim(unsigned Price);

  void conditionPriceSeptim(unsigned &Price);
  void conditionPlaceSeptim(unsigned &X, unsigned &Y);
};

#endif  // TESROUGEFALKREATH_SEPTIM_H
