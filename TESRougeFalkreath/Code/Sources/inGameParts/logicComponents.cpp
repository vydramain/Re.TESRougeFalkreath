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
  PLAYER_ = new player(Name, 30, 20, Race);
  return PLAYER_;
}

bool logicComponents::conditionPlayer(unsigned& X, unsigned& Y) {
  PLAYER_->viewLocation(X,Y);
  return false;
}

bool logicComponents::conditionPlayer(unsigned& X, unsigned& Y, unsigned& HP, unsigned& AP, unsigned& MP, unsigned& NATIONALITY,
                                      unsigned& STATUS, char* NAME) {
  PLAYER_->viewLocation(X, Y);
  PLAYER_->viewPoints(HP, AP, MP);
  PLAYER_->viewNationality(NATIONALITY);
  PLAYER_->viewName(NAME);
  return false;
}

bool logicComponents::actPLayer(unsigned typeACT, unsigned ACT) {
  switch (typeACT) {
    case 0: {
      return 0;
    }
    case 1: {
      char lay0, lay1, lay2, lay3;
      unsigned playerX, playerY;
      switch (ACT) {
        case 0: {
          PLAYER_->viewLocation(playerX, playerY);
          PLAYER_->changeCourse(0);
          MAP_->pullKnot(playerX, playerY - 1, lay0, lay1, lay2, lay3);
          if ((lay0 == ' ' || lay0 == '.') && lay1 == ' ' && lay2 == ' ' && lay3 == ' ') {
            PLAYER_->changeLocation(playerX, playerY - 1);
          }
          return 0;
        }
        case 1: {
          PLAYER_->viewLocation(playerX, playerY);
          PLAYER_->changeCourse(1);
          MAP_->pullKnot(playerX, playerY + 1, lay0, lay1, lay2, lay3);
          if ((lay0 == ' ' || lay0 == '.') && lay1 == ' ' && lay2 == ' ' && lay3 == ' ') {
            PLAYER_->changeLocation(playerX, playerY + 1);
          }
          return 0;
        }
        case 2: {
          PLAYER_->viewLocation(playerX, playerY);
          PLAYER_->changeCourse(2);
          MAP_->pullKnot(playerX - 1, playerY, lay0, lay1, lay2, lay3);
          if ((lay0 == ' ' || lay0 == '.') && lay1 == ' ' && lay2 == ' ' && lay3 == ' ') {
            PLAYER_->changeLocation(playerX - 1, playerY);
          }
          return 0;
        }
        case 3: {
          PLAYER_->viewLocation(playerX, playerY);
          PLAYER_->changeCourse(3);
          MAP_->pullKnot(playerX + 1, playerY, lay0, lay1, lay2, lay3);
          if ((lay0 == ' ' || lay0 == '.') && lay1 == ' ' && lay2 == ' ' && lay3 == ' ') {
            PLAYER_->changeLocation(playerX + 1, playerY);
          }
          return 0;
        }
        default: {
          return 1;
        }
      }
    }
    case 2: {
      return 0;
    }
    default: {
      return 1;
    }
  }
}

bool logicComponents::loadMap(const unsigned& Name, const unsigned& mapX, const unsigned& mapY, char** mapChar) {
  MAP_ = new playMap(Name, mapX, mapY);
  unsigned ggX, ggY;
  PLAYER_->viewLocation(ggX, ggY);
  if (MAP_) {
    for (unsigned ii(0); ii < mapY; ii++) {
      for (unsigned i(0); i < mapX; i++) {
        if (ii == ggY && i == ggX) {
          MAP_->changeKnot(i, ii, mapChar[ii][i], ' ', ' ', 'i');
        } else {
          MAP_->changeKnot(i, ii, mapChar[ii][i], ' ', ' ', ' ');
        }
      }
    }
    return true;
  } else {
    return MAP_;
  }
}

bool logicComponents::Update(unsigned typeACT, unsigned ACT) {
  if (actPLayer(typeACT, ACT)) {
    return true;
  }

  return false;
}