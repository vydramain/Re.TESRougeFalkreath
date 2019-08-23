//
// Created by vydra on 8/22/19.
//

#ifndef TESROUGEFALKREATH_CODE_HEADERS_INGAMEPARTS_LOGICCOMPONENTS_ITEMS_SEPTIM_H_
#define TESROUGEFALKREATH_CODE_HEADERS_INGAMEPARTS_LOGICCOMPONENTS_ITEMS_SEPTIM_H_

#include <controlComponents/playMap.h>
#include "inGameParts/logicComponents/item.h"

class septim : public item {
 private:
  unsigned price;

 public:
  septim();
  explicit septim(unsigned Count);
  explicit septim(unsigned X, unsigned Y, playMap *AREA);
  ~septim() {}

  bool placeSeptim(unsigned X, unsigned Y, playMap *AREA);
  bool priceSeptim(unsigned Price);

  unsigned conditionPriceSeptim();
  unsigned conditionPlaceSeptimX();
  unsigned conditionPlaceSeptimY();
};

#endif  // TESROUGEFALKREATH_CODE_HEADERS_INGAMEPARTS_LOGICCOMPONENTS_ITEMS_SEPTIM_H_
