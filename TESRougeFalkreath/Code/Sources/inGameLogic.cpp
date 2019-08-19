#include "inGameLogic.h"

inGameLogic::inGameLogic() {
  RENDER_ = new renderGame();
  LOGICA_ = new logicComponents();

  INPUT_ = new inputKey();
  DETERM_ = new inputDeterminant();
}
inGameLogic::inGameLogic(unsigned renderMode) {
  RENDER_ = new renderGame(renderMode);
  LOGICA_ = new logicComponents();

  INPUT_ = new inputKey();
  DETERM_ = new inputDeterminant();
}
inGameLogic::~inGameLogic() {
  delete RENDER_;
  delete LOGICA_;

  delete INPUT_;
  delete DETERM_;

  if (LOADFILE_) {
    delete LOADFILE_;
  }
  if (MAP_) {
    delete MAP_;
  }
}

unsigned inGameLogic::mainMenu() {
  bool isGO = false;
  unsigned nonshoise(0);
  do {
    RENDER_->clearALL();
    RENDER_->mainMenu(nonshoise);
    terminal_refresh();
    INPUT_->Update();
    if (INPUT_->IsUp() && nonshoise > 1) {
      nonshoise--;
    } else {
      if (INPUT_->IsDown() && nonshoise < 4) {
        nonshoise++;
      }
    }

    if (INPUT_->IsExit()) {
      nonshoise = 0;
      isGO = 1;
    } else {
      if (INPUT_->IsEnter() && nonshoise != 0) {
        isGO = 1;
      }
    }
  } while (!isGO);
  return nonshoise;
}

bool inGameLogic::newGame() {
  createPlayer();
  createMap();
  bool isExit = false;
  unsigned typeACT = 0;
  unsigned ACT = 0;
  do {
    INPUT_->Update();
    if (INPUT_->IsExit()) {
      return 1;
    }
      if(INPUT_->IsButtonEsc()){
        isExit = true;
      }

    DETERM_->whatMustToDo(INPUT_, typeACT, ACT);
    DETERM_->whatMustToGo(INPUT_, typeACT, ACT);

    LOGICA_->Update(typeACT, ACT);
    RENDER_->Update(LOGICA_);

  } while (!isExit);
  return false;
}

bool inGameLogic::createPlayer() {
  bool isGO = false;
  char Name[24];
  unsigned Race(0);

  for (unsigned i(0); i < 24; i++) {
    Name[i] = 0;
  }
  RENDER_->viewWord("Выбери имя: ", Name, 12, 24, 0, 0, 99, 39);
  terminal_refresh();

  do {
    RENDER_->raceMenu(Race);
    terminal_refresh();
    INPUT_->Update();
    if (INPUT_->IsUp() && Race > 1) {
      Race--;
    } else {
      if (INPUT_->IsDown() && Race < 10) {
        Race++;
      }
    }

    if (INPUT_->IsExit()) {
      Race = 0;
      isGO = 1;
    } else {
      if (INPUT_->IsEnter() && Race != 0) {
        isGO = 1;
      }
    }
  } while (!isGO);

  return LOGICA_->createPlayer(Name, Race);
}

bool inGameLogic::createMap() {
  unsigned mapX, mapY;
  char** mapChar = nullptr;

  LOADFILE_ = new loadFile("Maps/Falkreath.bin");
  LOADFILE_->loadMap(mapX, mapY, mapChar);
  delete LOADFILE_;

  return LOGICA_->loadMap(0, mapX, mapY, mapChar);
}
