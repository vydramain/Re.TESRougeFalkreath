#include "inGameParts/logicComponents.h"

logicComponents::logicComponents() {}

logicComponents::~logicComponents() {
  if (PLAYER_) {
    delete PLAYER_;
  }
  if (COIN_) {
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

unsigned logicComponents::conditionPlayerX() {
  return PLAYER_->viewLocationX();
}

unsigned logicComponents::conditionPlayerY() {
  return PLAYER_->viewLocationY();
}

unsigned logicComponents::conditionPlayerHP() {
  return PLAYER_->viewPointsHP();
}
unsigned logicComponents::conditionPlayerAP() {
  return PLAYER_->viewPointsAP();
}
unsigned logicComponents::conditionPlayerMP() {
  return PLAYER_->viewPointsAP();
}
unsigned logicComponents::conditionPlayerNATIONALITY() {
  return PLAYER_->viewNationality();
}
char* logicComponents::conditionPlayerNAME() {
  return PLAYER_->viewName();
}
unsigned logicComponents::conditionPlayerSTATUS() {
  return PLAYER_->viewStatus();
}
unsigned logicComponents::conditionPlayerWALLET() {
  return PLAYER_->viewCoinsCount();
}
unsigned logicComponents::conditionPlayerCOURSE() {
  return PLAYER_->viewCourse();
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
  unsigned R, seed;
  unsigned X[16] = {3, 8, 31, 57, 68, 64, 39, 72, 45, 61, 39, 16, 26, 35, 62, 77};
  unsigned Y[16] = {28, 46, 10, 6, 5, 21, 22, 72, 45, 52, 77, 72, 66, 81, 94, 26};
  COIN_ = new septim[10];
  for (unsigned i(0); i < 20; i++) {
    R = rand_r(&seed)% 16;
    COIN_[i].placeSeptim(X[R], Y[R], MAP_);
    COIN_[i].priceSeptim(R);
  }
  return false;
}

unsigned logicComponents::findCoin(unsigned X, unsigned Y) {
  unsigned coinX, coinY;
  for (unsigned i(0); i < 16; i++) {
    coinX = COIN_[i].conditionPlaceSeptimX();
    coinY = COIN_[i].conditionPlaceSeptimY();
    if (coinX == X && coinY == Y) {
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

bool logicComponents::conditionLogWindow() {
  return logWindow;
}

void logicComponents::changeOldAct(unsigned Act) {
  PLAYER_->changeOldAct(Act);
}

unsigned logicComponents::conditionOldAct() {
  return PLAYER_->conditionOldAct();
}

bool logicComponents::Update(const inputCommand_& containerCommand) {
  changeLogWindow(ECS_->EcsUpdate(containerCommand));
  return false;
}

void logicComponents::changeChangeArea(bool IN) {
  PLAYER_->changeChangeArea(IN);
}

bool logicComponents::conditionChangeArea() {
  return PLAYER_->conditionChangeArea();
}

bool logicComponents::conditionEnd() {
  return PLAYER_->conditionEndGame();
}
