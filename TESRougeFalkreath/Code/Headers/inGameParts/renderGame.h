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

  bool viewChoise(const char*, const char**, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
  bool mainMenu(unsigned);
};

#endif  // TESROUGEFALKREATH_CODE_HEADERS_INGAMEPARTS_RENDERGAME_H_
