//
// Created by vydra on 7/23/19.
//

#ifndef TESROUGEFALKREATH_INGAMELOGIC_H
#define TESROUGEFALKREATH_INGAMELOGIC_H

#include "./logicParts/Maps.h"

class inGameLogic {
 private:
  int mapX, mapY;

 public:
  inGameLogic() {}

  void inGameFT() {  //первый запуск
    Maps startMap(0);
    startMap.getSize(mapX, mapY);
  }
};

#endif  // TESROUGEFALKREATH_INGAMELOGIC_H
