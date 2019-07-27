//
// Created by vydra on 7/23/19.
//

#ifndef TESROUGEFALKREATH_CODE_HEADERS_INGAMELOGIC_H_
#define TESROUGEFALKREATH_CODE_HEADERS_INGAMELOGIC_H_

#include <logicParts/inputKey.h>
#include <logicParts/player.h>
#include "./logicParts/Maps.h"
#include "./renderGame.h"

class inGameLogic {
 private:
  int mapX, mapY;
  const inputKey &InputKey_;
  renderGame render;

  void update();

 public:
  inGameLogic(const inputKey &InputKey) : InputKey_(InputKey) {}
  void actionPlayer(hud &HUD, Maps &map, player &GG, int &xGG, int &yGG);
  bool movePlayer(player &GG, Maps &map, int &xGG, int &yGG);

  void inGameFT();
  // int action();
};

#endif  // TESROUGEFALKREATH_CODE_HEADERS_INGAMELOGIC_H_
