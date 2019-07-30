//
// Created by vydra on 7/23/19.
//

#ifndef TESROUGEFALKREATH_CODE_HEADERS_RENDERGAME_H_
#define TESROUGEFALKREATH_CODE_HEADERS_RENDERGAME_H_

#include <BearLibTerminal.h>
#include "./inputKey.h"
#include "logicParts/map.h"
#include "logicParts/player.h"

class renderGame {
 private:
  const int screenBorderX = 100;
  const int screenBorderY = 40;
  const int mapBorderY = 40;
  const int mapBorderX = 66;

  char nationality[13];

 public:
  renderGame() {}
  explicit renderGame(bool gameMode);
  renderGame(const renderGame &old) {}
  ~renderGame();
  renderGame &operator=(const renderGame &old) {
    return *this;
  }
  bool confirmAsk_ = false;
  unsigned question_ = 0;  // 0 - Нет вопроса
                           // 1 - Открыть Дверь?
                           // 2 - Спрятаться в зелени?

  bool explanationAsk_ = false;
  unsigned explanation_ = 0;  // 0 - Нет объяснения
                              // 1 - Это дверь. Похоже, из многовековой ели.
                              // 2 - Это хвойное растение. Похоже на ель.
                              // 3 - Камень. Мне через него не перебраться.
                              // 4 - Гладкая каменная стена... ...из хорошего булыжника.
                              // 5 - Пшеница... Несозревшая...
                              // 6 - Ствол... Просто ствол дерева...
                              // 7 - Забор деревянный. Добротный.
                              // 8 - Могила...     ...впервые вижу эти руны... ...скорее всего они из Атморы.
                              // 9 - Вода.

  void clearALL();
  void goRender(const map &currentMap, const player &GG);
  bool menuChoiser(unsigned &nonshoise, unsigned pointMuch);
  unsigned headMenu();
  bool inputQuestion(const char *zagolovok, unsigned zagolovokSize, char *GGName);
  unsigned inputChoose(const char **listMenu, const unsigned &menuPoint, const char *zagolovok, unsigned zagolovokSize);

  void symColor(char mapSym);
  void showMap(const map &currentLocation, int, int);
  void showPlayer(const player &GG);
  void showHud(const player &GG);
  void showDialog();
};

#endif  // TESROUGEFALKREATH_CODE_HEADERS_RENDERGAME_H_
