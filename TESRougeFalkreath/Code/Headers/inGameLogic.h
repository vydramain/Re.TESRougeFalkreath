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
  inputKey &InputKey_;
  renderGame render;


  void update();

 public:
  inGameLogic(inputKey &InputKey) : InputKey_(InputKey) {}
  void actionPlayer(hud &HUD, Maps &map, player &GG, int &xGG, int &yGG);
  bool movePlayer(player &GG, Maps &map, int &xGG, int &yGG);

  void inGameFT();
  //int action();
};

#endif  // TESROUGEFALKREATH_INGAMELOGIC_H
