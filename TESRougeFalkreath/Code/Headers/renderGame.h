//
// Created by vydra on 7/23/19.
//

#ifndef TESROUGEFALKREATH_CODE_HEADERS_RENDERGAME_H_
#define TESROUGEFALKREATH_CODE_HEADERS_RENDERGAME_H_

#include <BearLibTerminal.h>
#include "./inGameLogic.h"

class renderGame {
 private:
 public:
  explicit renderGame();

  void goRender();
  bool menuChoiser(unsigned &nonshoise, unsigned pointMuch);
  unsigned headMenu();
  bool inputQuestion(const char *zagolovok, char *GGName);
  unsigned inputChoose(const char **listMenu, const unsigned &menuPoint, const char *zagolovok);
};

#endif  // TESROUGEFALKREATH_CODE_HEADERS_RENDERGAME_H_
