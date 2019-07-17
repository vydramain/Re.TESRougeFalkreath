//
// Created by vydra on 7/15/19.
//

#ifndef TESROUGEFALKREATH_PLAYER_H
#define TESROUGEFALKREATH_PLAYER_H

#include <BearLibTerminal.h>
#include "collisio.h"
#include "inputKey.h"

class player {
 private:
  char symbol = 'i';
  const inputKey &InputKey_;
  unsigned x_ = 0, y_ = 0;

  void Render();

  void Move(collisio q, collisio w, collisio e, collisio r, collisio t, collisio y,collisio u,collisio i,collisio o);

 public:
  player(const inputKey &InputKey, unsigned x, unsigned y) : InputKey_(InputKey) , x_(x), y_(y) {}

  
  void Update(collisio q, collisio w, collisio e, collisio r, collisio t, collisio y,collisio u,collisio i,collisio o);
};

#endif  // TESROUGEFALKREATH_PLAYER_H
