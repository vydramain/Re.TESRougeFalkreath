//
// Created by vydra on 7/21/19.
//


#include "Maps.h"
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
    bool result= loadMap();
    if(result== 0){
        terminal_print(0, 0, "Ошбика при загрузке карты! loadMap_err");
        terminal_refresh();
    } else{
        terminal_print(0, 0, "Карта загружена...");
      terminal_refresh();
    }
  }
}

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
        //mapChar[ii][i]= fgetc(map);
      }
    }
    return true;
  }
}
void Maps::printMap(int xm, int ym) {
  /*bool mark;
  if(x<15 || x>30 || y<10 ||y>30){
    mark= true; // сдвинуть камеру надо
  } */


  for (int ii(0); ii < 40; ii++) {
    for (int i(0); i < 60; i++) {
      terminal_color(0xff989898);
              //printf("%c", mapChar[ym-20+ii][xm-30+i]);
              terminal_put(i, ii, mapChar[ym-20 + ii][xm-30+i]);




    }
    printf("\n");
  }
}