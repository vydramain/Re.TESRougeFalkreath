//
// Created by vydra on 7/15/19.
//

#include "../../Headers/logicParts/player.h"

void player::startPlayer(bool category) {
  if (category == false) {  // создание нового персонажа
  } else {                  // загрузка сохранения
    currentSave_.loadPlayer();
  }
}
void player::pullName(char* Name) {
  playerName_ = Name;
}
void player::pullNation(unsigned nation) {
  playerNation_ = nation;
}

void player::pullTerrain(unsigned xm, unsigned ym) {
  mapX = xm;
  mapY = ym;
}
/*
void player::getLocation(unsigned &x, unsigned &y) {
  x = x_;
  y = y_;
}
void player::putTerrain(unsigned xm, unsigned ym) {
  x_m = xm;
  y_m = ym;
}

void player::renderPlayer() {  // рендер персонажа

  terminal_color(0xffffffff);
  terminal_put_ext(x_, y_, 0, 0, naked);  //, 0xaaFFAAff);
}*/
