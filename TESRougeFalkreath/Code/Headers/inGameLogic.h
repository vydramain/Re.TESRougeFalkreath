//
// Created by vydra on 7/23/19.
//

#ifndef TESROUGEFALKREATH_CODE_HEADERS_INGAMELOGIC_H_
#define TESROUGEFALKREATH_CODE_HEADERS_INGAMELOGIC_H_

#include <inputKey.h>
#include "./renderGame.h"
#include "logicParts/World.h"
#include "logicParts/player.h"

class inGameLogic {
 private:
  const inputKey& InputKey_;
  renderGame render;
  World currentLocation_;
  player GG_;

  // void update();

 public:
  explicit inGameLogic(const inputKey& InputKey, bool NewGame);

  void createPlayer();
  // void actionPlayer(hud &HUD, Map &map, player &GG, int &xGG, int &yGG);
  // bool movePlayer(player &GG, Map &map, int &xGG, int &yGG);
  // void inGameFT();
  // int action();
};

#endif  // TESROUGEFALKREATH_CODE_HEADERS_INGAMELOGIC_H_
