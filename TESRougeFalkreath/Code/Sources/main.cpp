
#include <BearLibTerminal.h>
#include "./inGameLogic.h"
#include "./inputKey.h"
#include "./renderGame.h"

unsigned headMenu();

int main() {
  inputKey InputKey;
  renderGame render;
  unsigned gameStatus;
  gameStatus = render.headMenu();

  if (gameStatus == 1) {  // Новая игра
    inGameLogic game(InputKey, true);
  } else {
    if (gameStatus == 2) {
      return 0;
    }
  }
}
