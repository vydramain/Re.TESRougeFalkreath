//
// Created by vydra on 7/21/19.
//

#include "Maps.h"

Maps::Maps(unsigned in) {
  if (in == 0) {
    map = fopen("Maps/Falkreath.txt", "r");
  } else {
  }

  if (!map) {
    terminal_print(0, 0, "Карта не найдена!");
  } else {
    loadMap();
  }
}

bool Maps::loadMap() {
  fseek(map, 0, SEEK_SET);
  fscanf(map, "%u", &x_);
  fscanf(map, "%u", &y_);

  mapChar = new char *[y_];
  for (unsigned i(0); i < y_; i++) {
    mapChar[i] = new char[x_];
  }
  if (!mapChar) {
    terminal_print(0, 0, "Ошбика при загрузке карты! loadMap_err");
    return false;
  } else {
    for (unsigned ii(0); ii < y_; ii++) {
      for (unsigned i(0); i < x_; i++) {
        fscanf(map, "%c", &mapChar[ii][i]);
      }
    }
    terminal_print(0, 0, "Карта загружена...");
    return true;
  }
}
void Maps::printMap(unsigned x, unsigned y) {
  for (unsigned ii(0); ii < 40; ii++) {
    for (unsigned i(0); i < 60; i++) {
      terminal_put(i, ii, mapChar[x + i][y + ii]);
    }
  }
}