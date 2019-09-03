#ifndef TESROUGEFALKREATH_CODE_HEADERS_INGAMEPARTS_RENDERGAME_H_
#define TESROUGEFALKREATH_CODE_HEADERS_INGAMEPARTS_RENDERGAME_H_

#include <BearLibTerminal.h>
#include "inGameParts/logicComponents.h"

#define HUDLAYER 13
#define SCREENMODE1X 100
#define SCREENMODE1Y 40

class renderGame {
 private:
  unsigned mapBorderX_ = 66, mapBorderY_ = 40;

  unsigned stepMeter_;
  unsigned oldPlayerX_, oldPlayerY_;

 public:
  explicit renderGame();
  explicit renderGame(unsigned gameMode);
  ~renderGame();

  void clearALL();
  void clearAREA(unsigned inX, unsigned inY, unsigned outX, unsigned outY);

  bool viewPhrase(const char*, const char*, unsigned, unsigned, unsigned, unsigned);
  bool viewWord(const char*, char*, unsigned, unsigned, unsigned, unsigned, unsigned,
                unsigned);  // Что вводишь, возврат того, что вводишь, размер первого слова, размер второго слова, координаты
                            // квадрата, где производится ввод
  bool viewChoise(const char*, const char**, unsigned, unsigned, unsigned, unsigned, unsigned,
                  unsigned);  // Заголовок, список из меню, колличество пунктов для выбора, выбранный пункт, координаты квадрата для выбора

  bool mainMenu(unsigned);  // Выделенный элемент      содежит terminal_refresh
  bool raceMenu(unsigned);  // Аналог верхнего         содежит terminal_refresh

  void symColor(char Symbol);
  void showArea(logicComponents* COMPONENTS);
  void showPlayer(logicComponents* COMPONENTS);
  void showHud(logicComponents* COMPONENTS);
  void showLogWindow(logicComponents* COMPONENTS);

  bool   Update(logicComponents* COMPONENTS);  // содежит terminal_refresh

  bool deathScreen(logicComponents* COMPONENTS);  // содежит terminal_refresh
};

#endif  // TESROUGEFALKREATH_CODE_HEADERS_INGAMEPARTS_RENDERGAME_H_
