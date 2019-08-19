#ifndef TESROUGEFALKREATH_CODE_HEADERS_INGAMEPARTS_RENDERGAME_H_
#define TESROUGEFALKREATH_CODE_HEADERS_INGAMEPARTS_RENDERGAME_H_

#include <BearLibTerminal.h>

#define HUDLAYER 13
#define SCREENMODE1X 100
#define SCREENMODE1Y 40

class renderGame {
 private:
 public:
  explicit renderGame();
  explicit renderGame(unsigned);
  ~renderGame();

  void clearALL();

  bool viewWord(const char*, char*, unsigned, unsigned, unsigned, unsigned, unsigned,
                 unsigned);  // Что вводишь, возврат того, что вводишь, размер первого слова, размер второго слова, координаты
                                   // квадрата, где производится ввод
  bool viewChoise(
      const char*, const char**, unsigned, unsigned, unsigned, unsigned, unsigned,
       unsigned);  // Заголовок, список из меню, колличество пунктов для выбора, выбранный пункт, координаты квадрата для выбора

  bool mainMenu(unsigned);  // Выделенный элемент
  bool raceMenu(unsigned);  // Аналог верхнего
};

#endif  // TESROUGEFALKREATH_CODE_HEADERS_INGAMEPARTS_RENDERGAME_H_
