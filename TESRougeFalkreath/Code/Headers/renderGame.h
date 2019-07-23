//
// Created by vydra on 7/23/19.
//

#ifndef TESROUGEFALKREATH_RENDERGAME_H
#define TESROUGEFALKREATH_RENDERGAME_H

#include "./logicParts/Maps.h"
#include "./logicParts/hud.h"
#include "./logicParts/player.h"

class renderGame {
 private:


 public:
  renderGame() {}
  void goRender(Maps map, player gg, hud interface);

};

#endif  // TESROUGEFALKREATH_RENDERGAME_H
