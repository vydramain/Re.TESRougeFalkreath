//
// Created by vydra on 7/21/19.
//

#include "logicParts/World/Map.h"

Map::Map(unsigned mapNumber) {
  if (mapNumber == 0) {
    mapName_ = "Falkreath";
    if (!currentMap_.loadMap("Maps/Falkreath.bin", mapXSize_, mapYSize_, mapChar_)) {
      errsMap = true;
    }
  }
}

Map::~Map() {
  for (int i(0); i < mapYSize_; i++) {
    delete mapChar_[i];
  }
  delete mapChar_;
  delete mapName_;
}

/*  if (in == 0) {
    map = fopen("Maps/Falkreath.bin", "r");
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

Map::~Map() {
  for (int ii = 0; ii < y_; ii++) {
    delete[] mapChar[ii];
  }
  delete[] mapChar;
  x_ = 0;
  y_ = 0;
};

bool Map::loadMap() {
  fseek(map, 0, SEEK_SET);
  fscanf(map, "%u ", &x_);
  fscanf(map, "%u ", &y_);

  mapChar = new char *[y_];
  for (int i(0); i < y_; i++) {
    mapChar[i] = new char[x_];
  }
  if (!mapChar) {
    return false;
  } else {
    for (int ii(0); ii < y_; ii++) {
      for (int i(0); i < x_; i++) {
        mapChar[ii][i] = fgetc(map);
      }
    }
    return true;
  }
}

void Map::getSize(int &x, int &y) {
  x = x_;
  y = y_;
}

char Map::getSymbol(int xM, int yM) {
  if (xM < 0 || yM < 0) {
    return ']';
  } else {
    if (x_ < xM || y_ < yM) {
      return ']';
    } else {
      return mapChar[yM][xM];
    }
  }
}

void Map::symColor(char mapSym) {
  if (mapSym == '~') {
    terminal_color(0xff009fff);
  } else {
    if (mapSym == ';' || mapSym == '+' || mapSym == '-' || mapSym == '?' || mapSym == ':' || mapSym == 'J' ||
        mapSym == '`' || mapSym == '9' || mapSym == '|') {
      terminal_color(0xff009f00);
    } else {
      if (mapSym == ']' || mapSym == '}' || mapSym == '{' || mapSym == '[' || mapSym == '_') {
        terminal_color(0xff7f7f7f);
      } else {
        if (mapSym == 'W' || mapSym == 'w' || mapSym == 'V') {
          terminal_color(0xffe8d384);
        } else {
          if (mapSym == '"' || mapSym == '=' || mapSym == '>' || mapSym == '^' || mapSym == 'v' || mapSym == '<') {
            terminal_color(0xff91846f);
          } else {
            if (mapSym == 'Q' || mapSym == 'P' || mapSym == '6' || mapSym == ')' || mapSym == '(' || mapSym == 'Q' ||
                mapSym == 'j') {
              terminal_color(0xff6f6f6f);
            } else {
              if (mapSym == 'L') {
                terminal_color(0xff1aff00);
              } else {
                if (mapSym == 'A') {
                  terminal_color(0xFFFF0000);
                } else {
                  if (mapSym == 't') {
                    terminal_color(0xFFABABAB);
                  } else {
                    terminal_color(0x77a0a0a0);
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}

//////////////////////////////////////////////////////////////рендер
void Map::renderMap(int xm, int ym) {
  for (int ii(0); ii < 40; ii++) {
    for (int i(0); i < 60; i++) {
      terminal_color(0xaaffffff);
      if (ym - 20 + ii < 0) {
        terminal_put(i, ii, ' ');
      } else {
        if (xm - 30 + i < 0) {
          terminal_put(i, ii, ' ');
        } else {
          if (ym - 20 + ii > y_) {
            terminal_put(i, ii, ' ');
          } else {
            if (xm - 30 + i > x_) {
              terminal_put(i, ii, ' ');
            } else {
              symColor(mapChar[ym - 20 + ii][xm - 30 + i]);
              terminal_put(i, ii, mapChar[ym - 20 + ii][xm - 30 + i]);
            }
          }
        }
      }
    }
  }
}*/
