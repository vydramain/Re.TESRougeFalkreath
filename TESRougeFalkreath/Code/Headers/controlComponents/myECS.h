//
// Created by vydra on 8/21/19.
//

#ifndef TESROUGEFALKREATH_MYECS_H
#define TESROUGEFALKREATH_MYECS_H

#include <inGameParts/logicComponents/player.h>
#include "controlComponents/inputCommand.h"
#include "controlComponents/playMap.h"

class myECS {
 private:
  playMap *MAP_;
  player *PLAYER_;

  bool lastReturn_;
 public:
  myECS();
  myECS(playMap *, player *);
  ~myECS();

  bool EcsUpdate(inputCommand_);
};

#endif  // TESROUGEFALKREATH_MYECS_H
