//
// Created by vydra on 7/21/19.
//

#include "../../Headers/logicParts/Maps.h"
#include <stdio.h>

Maps::Maps(unsigned in) {
  if (in == 0) {
    map = fopen("Maps/Falkreath.bin", "rt");
  } else {
  }

  if (!map) {
    terminal_print(0, 0, "Карта не найдена!");
    terminal_refresh();
  } else {
    bool result = loadMap();
    if (result == 0) {
      terminal_print(0, 0, "Ошбика при загрузке карты! loadMap_err");
      terminal_refresh();
    } else {
      fclose(map);
      terminal_print(0, 0, "Карта загружена...");
      terminal_refresh();
    }
  }
}

Maps::~Maps() {
  for (int ii = 0; ii < y_; ii++) {
    delete[] mapChar[ii];
  }
  delete[] mapChar;
  x_ = 0;
  y_ = 0;
};

bool Maps::loadMap() {
  fseek(map, 0, SEEK_SET);
  fscanf(map, "%u", &x_);
  fscanf(map, "%u", &y_);

  mapChar = new char *[y_];
  for (int i(0); i < y_; i++) {
    mapChar[i] = new char[x_];
  }
  if (!mapChar) {
    return false;
  } else {
    for (int ii(0); ii < y_; ii++) {
      for (int i(0); i < x_; i++) {
        fscanf(map, "%c", &mapChar[ii][i]);
        // mapChar[ii][i]= fgetc(map);
      }
    }
    return true;
  }
}

void Maps::getSize(int &x, int &y) {
  x = x_;
  y = y_;
}



//////////////////////////////////////////////////////////////рендер
void Maps::renderMap(int xm, int ym){
    terminal_color(0xffa0a0a0);
    for (int ii(0); ii < 40; ii++) {
        for (int i(0); i < 60; i++) {
            terminal_color(0xff989898);
            if(ym-20+ii< 0){
              terminal_put(i,ii,' ');
            }else {
              if (xm - 30 + i < 0) {
                terminal_put(i, ii, ' ');
              }else{
                if(ym-20+ii> y_){
                  terminal_put(i, ii, ' ');
                }else{
                  if(xm - 30 + i > x_) {
                    terminal_put(i, ii, ' ');
                  } else{
              terminal_put(i, ii, mapChar[ym - 20 + ii][xm - 30 + i]);
            }}}}



        }

    }
}