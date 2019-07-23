//
// Created by vydra on 7/23/19.
//

#ifndef TESROUGEFALKREATH_INGAMELOGIC_H
#define TESROUGEFALKREATH_INGAMELOGIC_H

#include "./renderGame.h"
#include <logicParts/inputKey.h>
#include <logicParts/player.h>
#include "./logicParts/Maps.h"


class inGameLogic {
 private:
  int mapX, mapY;
  const inputKey &InputKey_;
  renderGame render;


  void update();

 public:
  inGameLogic(const inputKey &InputKey) : InputKey_(InputKey) {}

  void inGameFT();
};

#endif  // TESROUGEFALKREATH_INGAMELOGIC_H
