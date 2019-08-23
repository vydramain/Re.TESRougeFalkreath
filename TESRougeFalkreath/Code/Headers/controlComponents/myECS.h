//
// Created by vydra on 8/21/19.
//

#ifndef TESROUGEFALKREATH_CODE_HEADERS_CONTROLCOMPONENTS_MYECS_H_
#define TESROUGEFALKREATH_CODE_HEADERS_CONTROLCOMPONENTS_MYECS_H_

#include <inGameParts/logicComponents/items/septim.h>
#include <inGameParts/logicComponents/player.h>
#include "controlComponents/inputCommand.h"
#include "controlComponents/playMap.h"

class myECS {
 private:
  playMap *MAP_;
  player *PLAYER_;
  septim *COIN_;

  bool lastReturn_;

 public:
  myECS();
  myECS(playMap *, player *, septim *);
  ~myECS();

  bool EcsUpdate(inputCommand_);
};

#endif  // TESROUGEFALKREATH_CODE_HEADERS_CONTROLCOMPONENTS_MYECS_H_
