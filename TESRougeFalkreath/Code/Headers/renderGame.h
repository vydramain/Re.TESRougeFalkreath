//
// Created by vydra on 7/23/19.
//

#ifndef TESROUGEFALKREATH_CODE_HEADERS_RENDERGAME_H_
#define TESROUGEFALKREATH_CODE_HEADERS_RENDERGAME_H_

#include <BearLibTerminal.h>
#include "./inputKey.h"
#include "logicParts/player.h"
#include "logicParts/map.h"

class renderGame {
 private:
 public:
  renderGame() {}
  explicit renderGame(bool gameMode);
  renderGame(const renderGame &old) {}
  ~renderGame();
  renderGame &operator=(const renderGame &old) {
    return *this;
  }

  void goRender(const map &currentMap, const player &GG);
  bool menuChoiser(unsigned &nonshoise, unsigned pointMuch);
  unsigned headMenu();
  bool inputQuestion(const char *zagolovok, unsigned zagolovokSize, char *GGName);
  unsigned inputChoose(const char **listMenu, const unsigned &menuPoint, const char *zagolovok, unsigned zagolovokSize);

  void symColor(char mapSym);
  void showMap(const map &currentLocation, int, int);
  void showPlayer(const player &GG);
};

#endif  // TESROUGEFALKREATH_CODE_HEADERS_RENDERGAME_H_
