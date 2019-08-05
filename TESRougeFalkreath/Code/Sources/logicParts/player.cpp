//
// Created by vydra on 7/15/19.
//

#include "../../Headers/logicParts/player.h"

player::player() {
  for (unsigned i(0); i < 12; i++) {
    playerName_[i] = 0;
  }
}

player::~player() {}

void player::startPlayer(bool category) {
  if (category == false) {  // создание нового персонажа
  } else {                  // загрузка сохранения
    currentSave_.loadPlayer();
  }
}

void player::pullTerrain(unsigned xm, unsigned ym) {
  mapX_ = xm;
  mapY_ = ym;
  screenX_ = mapX_;
  screenY_ = mapY_;
}

// void player::putItem(items *Item) {}
