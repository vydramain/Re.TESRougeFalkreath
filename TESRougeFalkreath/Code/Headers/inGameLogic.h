//
// Created by vydra on 7/23/19.
//

#ifndef TESROUGEFALKREATH_CODE_HEADERS_INGAMELOGIC_H_
#define TESROUGEFALKREATH_CODE_HEADERS_INGAMELOGIC_H_

#include <inGameParts/renderGame.h>
#include "controlComponents/inputCommand.h"
#include "controlComponents/inputDeterminant.h"
#include "controlComponents/inputKey.h"
#include "controlComponents/loadFile.h"
#include "controlComponents/playMap.h"
#include "inGameParts/logicComponents.h"
#define FRAMES_PER_SECOND_ 0.008

class inGameLogic {
 private:
  logicComponents *LOGICA_ = nullptr;
  renderGame *RENDER_ = nullptr;

  inputKey *INPUT_ = nullptr;
  inputDeterminant *DETERM_ = nullptr;
  loadFile *LOADFILE_ = nullptr;
  playMap *MAP_ = nullptr;

 public:
  explicit inGameLogic();
  explicit inGameLogic(unsigned);
  ~inGameLogic();

  unsigned mainMenu();
  bool newGame();
  bool loadGame();
  bool setGame();

  bool putPlayer();
  bool createPlayer();
  bool createMap();
  bool createECS();

  bool reloadMap();
};

#endif  // TESROUGEFALKREATH_CODE_HEADERS_INGAMELOGIC_H_
