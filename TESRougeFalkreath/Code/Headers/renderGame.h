//
// Created by vydra on 7/23/19.
//

#ifndef TESROUGEFALKREATH_CODE_HEADERS_RENDERGAME_H_
#define TESROUGEFALKREATH_CODE_HEADERS_RENDERGAME_H_

#include "./logicParts/Maps.h"
#include "./logicParts/hud.h"
#include "./logicParts/player.h"

class renderGame {
 private:
 public:
  renderGame() {}
  void goRender(Maps &map, player &gg, hud &interface);
};

#endif  // TESROUGEFALKREATH_CODE_HEADERS_RENDERGAME_H_
