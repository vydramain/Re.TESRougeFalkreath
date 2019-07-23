//
// Created by vydra on 7/23/19.
//

#ifndef TESROUGEFALKREATH_INGAMELOGIC_H
#define TESROUGEFALKREATH_INGAMELOGIC_H

#include <logicParts/inputKey.h>
#include <logicParts/player.h>
#include "./logicParts/Maps.h"

class inGameLogic {
 private:
  int mapX, mapY;
  const inputKey &InputKey_;

  void update();

 public:
  inGameLogic(const inputKey &InputKey) : InputKey_(InputKey) {}

  void inGameFT() {  //первый запуск

    Maps startMap(0);
    startMap.getSize(mapX, mapY);
    player GG(40, 20);
    
  }
};

#endif  // TESROUGEFALKREATH_INGAMELOGIC_H
