//
// Created by vydra on 7/23/19.
//

#ifndef TESROUGEFALKREATH_CODE_HEADERS_INGAMELOGIC_H_
#define TESROUGEFALKREATH_CODE_HEADERS_INGAMELOGIC_H_

#include "controlComponents/inputKey.h"
#include "controlComponents/inputDeterminant.h"
#include "controlComponents/playMap.h"
#include "controlComponents/loadFile.h"
#include "inGameParts/logicComponents.h"
#include <inGameParts/renderGame.h>
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

  bool createPlayer();
  bool createMap();
};

#endif  // TESROUGEFALKREATH_CODE_HEADERS_INGAMELOGIC_H_
