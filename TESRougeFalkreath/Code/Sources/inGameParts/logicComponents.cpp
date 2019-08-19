#include "inGameParts/logicComponents.h"

logicComponents::logicComponents() {}

logicComponents::~logicComponents() {
  if (PLAYER_) {
    delete PLAYER_;
  }
  if (MAP_) {
    delete MAP_;
  }
}

bool logicComponents::createPlayer(char* Name, unsigned Race) {
  PLAYER_ = new player(Name, 49, 20, Race);
  return PLAYER_;
}

bool logicComponents::loadMap(const unsigned& Name, const unsigned& mapX, const unsigned& mapY, char** mapChar) {
  MAP_ = new playMap(Name, mapX, mapY);
  if (MAP_) {
    for (unsigned ii(0); ii < mapY; ii++) {
      for (unsigned i(0); i < mapX; i++) {
        MAP_->changeKnot(i, ii, mapChar[ii][i], ' ', ' ', ' ');
      }
    }
    return true;
  } else {
    return MAP_;
  }
}