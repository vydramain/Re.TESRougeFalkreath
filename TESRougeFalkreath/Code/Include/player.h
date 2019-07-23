//
// Created by vydra on 7/15/19.
//

#ifndef TESROUGEFALKREATH_CODE_INCLUDE_PLAYER_H
#define TESROUGEFALKREATH_CODE_INCLUDE_PLAYER_H

#include <BearLibTerminal.h>
#include "inputKey.h"

class player {
 private:
  char symbol = 'i';
  const inputKey &InputKey_;
  unsigned x_ = 0, y_ = 0; // для отображения на экране
  unsigned x_m= 30, y_m= 20; // для размещения на карте


  void Move();

 public:
  player(const inputKey &InputKey, unsigned x, unsigned y) : InputKey_(InputKey), x_(x), y_(y) {}
  void render();
  void getTerrain(unsigned &xm, unsigned &ym);
  void getLocation(unsigned &x, unsigned &y);



};

#endif  // TESROUGEFALKREATH_CODE_INCLUDE_PLAYER_H
