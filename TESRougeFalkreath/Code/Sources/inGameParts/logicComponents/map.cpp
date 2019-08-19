#include "inGameParts/logicComponents/map.h"

map::map() {
  mapName_ = 0;
  mapChar_ = nullptr;

  mapXSize_ = 0;
  mapYSize_ = 0;
  errsMap_ = 0;
}

map::map(const unsigned& NAME, const unsigned& X, const unsigned& Y, char** mapChar) {
  mapName_ = NAME;
  mapXSize_ = X;
  mapYSize_ = Y;

  mapChar_ = new char*[mapYSize_];
  for (unsigned ii(0); ii < mapYSize_; ii++) {
    mapChar_[ii] = new char[mapXSize_];
  }

  if (!mapChar_) {
    for (unsigned i(0); i < mapYSize_; i++) {
      delete []mapChar_[i];
    }
    delete []mapChar_;
    mapName_ = 0;
    mapXSize_ = 0;
    mapYSize_ = 0;
    errsMap_ = 1;
  } else {
    for (unsigned ii(0); ii < mapYSize_; ii++) {
      for (unsigned i(0); i < mapXSize_; i++) {
        mapChar_[ii][i] = mapChar[ii][i];
      }
    }
    errsMap_ = 0;
  }
}

map::~map() {
  for (unsigned i = 0; i < mapYSize_; ++i) {
    delete []mapChar_;
  }
  delete []mapChar_;
}

char map::viewMapChar(const unsigned& X, const unsigned& Y) {
  if(X >= mapXSize_ || Y >= mapYSize_){
    return ' ';
  } else{
    return mapChar_[Y][X];
  }
}