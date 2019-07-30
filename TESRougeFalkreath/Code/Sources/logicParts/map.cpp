//
// Created by vydra on 7/21/19.
//

#include "logicParts/map.h"

map::map() {}

map::~map() {
  // for (int i(0); i < mapYSize_; i++) {
  //    delete mapChar_[i];
  //  }
  //  delete mapChar_;
}

map& map::operator=(const map& old) {
  if (this != &old) {
    errsMap = old.errsMap;
    mapXSize_ = old.mapXSize_;
    mapYSize_ = old.mapYSize_;
    strcpy(mapName_, old.mapName_);
    for (int i(0); i < mapYSize_; i++) {
      for (int ii(0); ii < mapXSize_; ii++) {
        mapChar_[i][ii] = old.mapChar_[i][ii];
      }
    }
  }
  return *this;
}

bool map::choiseMap(unsigned mapNumber) {
  if (mapNumber == 0) {
    if (!currentMap_.loadMap("Maps/Falkreath.bin", mapXSize_, mapYSize_, mapName_, mapChar_)) {
      errsMap = true;
      return true;
    }
  }
  return false;
}

char map::getSymbol(int xGG, int yGG) {
  if (xGG < 0 || xGG > mapXSize_) {
    return ' ';
  } else {
    if (yGG < 0 || yGG > mapYSize_) {
      return ' ';
    } else {
      return mapChar_[yGG][xGG];
    }
  }
}
