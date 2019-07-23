//
// Created by vydra on 7/15/19.
//

#include "../../Headers/logicParts/player.h"

void player::getTerrain(unsigned &xm, unsigned &ym) {
  xm = x_m;
  ym = y_m;
}
void player::getLocation(unsigned &x, unsigned &y) {
  x = x_;
  y = y_;
}
void player::putTerrain(unsigned xm, unsigned ym){
  x_m= xm;
  y_m= ym;
}

void player::renderPlayer() { // рендер персонажа

    terminal_color(0xffffffff);
    terminal_put_ext(x_, y_, 0 , 0, naked); //, 0xaaFFAAff);

}