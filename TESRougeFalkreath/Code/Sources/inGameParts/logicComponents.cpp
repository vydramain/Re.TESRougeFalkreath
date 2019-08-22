#include "inGameParts/logicComponents.h"

logicComponents::logicComponents() {}

logicComponents::~logicComponents() {
  if (PLAYER_) {
    delete PLAYER_;
  }
  if(COIN_){
    delete[] COIN_;
  }
  if (MAP_) {
    delete MAP_;
  }
}

bool logicComponents::createPlayer(char* Name, unsigned Race) {
  PLAYER_ = new player(Name, 73, 14);
  PLAYER_->changeNationality(Race);
  PLAYER_->changeStatus(1);
  return PLAYER_;
}

bool logicComponents::putPlayer(unsigned map) {
  if (map == 0) {
    return PLAYER_->changeLocation(73, 14);
  } else {
    if (map == 1) {
      return PLAYER_->changeLocation(4, 16);
    } else {
      return true;
    }
  }
}

bool logicComponents::conditionPlayer(unsigned& X, unsigned& Y) {
  PLAYER_->viewLocation(X, Y);
  return false;
}

bool logicComponents::conditionPlayer(unsigned& X, unsigned& Y, unsigned& Course) {
  PLAYER_->viewLocation(X, Y);
  PLAYER_->viewCourse(Course);
  return false;
}

bool logicComponents::conditionPlayer(unsigned& X, unsigned& Y, unsigned& HP, unsigned& AP, unsigned& MP, unsigned& NATIONALITY,
                                      unsigned& STATUS, char* NAME, unsigned& WALLET) {
  PLAYER_->viewLocation(X, Y);
  PLAYER_->viewPoints(HP, AP, MP);
  PLAYER_->viewNationality(NATIONALITY);
  PLAYER_->viewName(NAME);
  PLAYER_->viewStatus(STATUS);
  PLAYER_->viewCoinsCount(WALLET);
  return false;
}

bool logicComponents::loadMap(const unsigned& Name, const unsigned& mapX, const unsigned& mapY, char** mapChar) {
  if (MAP_) {
    delete MAP_;
  }
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

bool logicComponents::createCoin() {
  srand(time(nullptr));
  unsigned R;
  unsigned X[16] = {3,8,31,57,68,64,39,72,45,61,39,16,26,35,62,77};
  unsigned Y[16] = {28,46,10,6,5,21,22,72,45,52,77,72,66,81,94,26};
    COIN_ = new septim[10];
  for(unsigned i(0); i < 20; i++){
    R = rand() % 16;
    COIN_[i].placeSeptim(X[R], Y[R], MAP_);
    COIN_[i].priceSeptim(R);
  }
  return false;
}

unsigned logicComponents::findCoin(unsigned X, unsigned Y) {
  unsigned coinX, coinY;
  for(unsigned i (0); i < 16; i++){
    COIN_[i].conditionPlaceSeptim(coinX, coinY);
    if (coinX == X && coinY == Y){
      return i++;
    }
  }
  return 0;
}

bool logicComponents::deleteCoin() {
  delete[] COIN_;
  return false;
}

bool logicComponents::createECS() {
  if (MAP_ && PLAYER_) {
    ECS_ = new myECS(MAP_, PLAYER_, COIN_);
    return false;
  } else {
    return true;
  }
}

void logicComponents::changeLogWindow(bool Log) {
  logWindow = Log;
}

void logicComponents::conditionLogWindow(bool& Log) {
  Log = logWindow;
}

void logicComponents::changeOldAct(unsigned Act) {
  PLAYER_->changeOldAct(Act);
}

void logicComponents::conditionOldAct(unsigned& Act) {
  PLAYER_->conditionOldAct(Act);
}

bool logicComponents::Update(const inputCommand_& containerCommand) {
  changeLogWindow(ECS_->EcsUpdate(containerCommand));
  return false;
}

void logicComponents::changeChangeArea(bool IN) {
  PLAYER_->changeChangeArea(IN);
}

void logicComponents::conditionChangeArea(bool& IN) {
  PLAYER_->conditionChangeArea(IN);
}

void logicComponents::conditionEnd(bool& IN) {
  PLAYER_->conditionEndGame(IN);
}