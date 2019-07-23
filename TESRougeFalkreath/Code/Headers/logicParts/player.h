//
// Created by vydra on 7/15/19.
//

#ifndef TESROUGEFALKREATH_CODE_INCLUDE_PLAYER_H
#define TESROUGEFALKREATH_CODE_INCLUDE_PLAYER_H

#include <BearLibTerminal.h>

class player {
 private:
  char naked = 'i';  //игрок без брони

  unsigned course; /*  направление в котором последний раз двигался персонаж  0 -вврех,
                                                                              1 -влево,
                                                                              2 -вправо,
                                                                              3 -вниз,
                                                                              4 -никуда не напрвален.*/
  unsigned x_ = 0, y_ = 0;    // для отображения на экране
  unsigned x_m = 0, y_m = 0;  // для размещения на карте

  char *playerName;
  unsigned Race;
  unsigned HP;
  unsigned MP;
  unsigned AP;
  unsigned SP;

 public:
  player(unsigned xm, unsigned ym) : x_m(xm), y_m(ym) {}
  void getTerrain(unsigned &xm, unsigned &ym);
  void getLocation(unsigned &x, unsigned &y);

  //////////////////////////////////////////////////////////////рендер
  void renderPlayer();
};

#endif  // TESROUGEFALKREATH_CODE_INCLUDE_PLAYER_H
