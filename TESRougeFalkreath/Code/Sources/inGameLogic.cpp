#include "./inGameLogic.h"

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
  createCoin();
  createECS();
  bool exit = gameLoop();
  deleteCoin();
  if (checkEnd()) {
    RENDER_->deathScreen(LOGICA_);
    terminal_refresh();
    terminal_read();
  }
  return exit;
}

bool inGameLogic::putPlayer() {
  playMap* Map;
  unsigned mapName;
  Map = LOGICA_->secret();
  mapName = Map->viewName();
  return LOGICA_->putPlayer(mapName);
}

bool inGameLogic::createPlayer() {
  bool isGO = false;
  char Name[24];
  unsigned Race(0);

  for (unsigned i(0); i < 24; i++) {
    Name[i] = 0;
  }
  RENDER_->viewWord("Выбери имя: ", Name, 12, 24, 0, 0, 99, 39);
  RENDER_->clearALL();

  do {
    RENDER_->raceMenu(Race);
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

  return LOGICA_->loadMap(0, mapX, mapY, mapChar);
}

bool inGameLogic::createCoin() {
  return LOGICA_->createCoin();
}

bool inGameLogic::createECS() {
  return LOGICA_->createECS();
}

bool inGameLogic::deleteCoin() {
  LOGICA_->deleteCoin();
  return false;
}

bool inGameLogic::checkEnd() {
  return LOGICA_->conditionEnd();
}

bool inGameLogic::reloadMap() {
  bool status = LOGICA_->conditionChangeArea();
  if (status) {
    if (LOADFILE_) {
      delete LOADFILE_;
    }
    playMap* Map;
    unsigned mapX, mapY, mapName;
    char** mapChar = nullptr;
    Map = LOGICA_->secret();
    mapName = Map->viewName();
    if (mapName == 0) {
      LOADFILE_ = new loadFile("Maps/WestForest.bin");
      LOADFILE_->loadMap(mapX, mapY, mapChar);

      LOGICA_->changeChangeArea(false);
      LOGICA_->putPlayer(1);
      return LOGICA_->loadMap(1, mapX, mapY, mapChar);
    } else {
      LOADFILE_ = new loadFile("Maps/Falkreath.bin");
      LOADFILE_->loadMap(mapX, mapY, mapChar);

      LOGICA_->changeChangeArea(false);
      LOGICA_->putPlayer(0);
      return LOGICA_->loadMap(0, mapX, mapY, mapChar);
    }
  }
  LOGICA_->changeChangeArea(false);
  return false;
}

bool inGameLogic::deathScreen() {
  RENDER_->deathScreen(LOGICA_);
  return false;
}

bool inGameLogic::gameLoop() {
  bool isExit = false;
  inputCommand_ containerCommand;
  do {
    INPUT_->Update();
    if (INPUT_->IsExit()) {
      return true;
    }
    if (INPUT_->IsButtonEsc() || checkEnd()) {
      isExit = true;
    }

    containerCommand = DETERM_->determineInputKey(INPUT_);

    LOGICA_->Update(containerCommand);
    RENDER_->Update(LOGICA_);

    reloadMap();
  } while (!isExit);
  return false;
}
