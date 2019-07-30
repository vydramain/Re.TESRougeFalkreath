//
// Created by vydra on 7/23/19.
//

#ifndef TESROUGEFALKREATH_CODE_HEADERS_INGAMELOGIC_H_
#define TESROUGEFALKREATH_CODE_HEADERS_INGAMELOGIC_H_

#include <inputKey.h>
#include "./renderGame.h"
#include "logicParts/player.h"

class inGameLogic {
 private:
  inputKey &InputKey_;
  player GG_;
  map CurrentMap_;

  bool movePlayer();
  void actionPlayer();
  void Update();

 public:
  explicit inGameLogic(inputKey &InputKey, bool NewGame);
  void createPlayer(renderGame &Render);
  void play(renderGame &Render);
  // void actionPlayer(hud &HUD, map &map, player &GG, int &xGG, int &yGG);
  // bool movePlayer(player &GG, map &map, int &xGG, int &yGG);
  // void inGameFT();
  // int action();
};

#endif  // TESROUGEFALKREATH_CODE_HEADERS_INGAMELOGIC_H_
