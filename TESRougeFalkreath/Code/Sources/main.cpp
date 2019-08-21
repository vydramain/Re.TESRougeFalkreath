#include "inGameLogic.h"

int main() {
  inGameLogic GAME(1);
  unsigned nextPUNCT;
  do {
    nextPUNCT = GAME.mainMenu();
    switch (nextPUNCT) {
      case 1: {
        if (GAME.newGame() == true) {
          nextPUNCT = 4;
        }
        break;
      }
      case 2: {
        break;
      }
      case 3: {
        break;
      }
      default: {
        break;
      }
    }
  } while (nextPUNCT > 0 && nextPUNCT < 4);

  return 0;
}
