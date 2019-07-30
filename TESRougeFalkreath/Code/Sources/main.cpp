
#include <BearLibTerminal.h>
#include "./inGameLogic.h"
#include "./inputKey.h"
#include "./renderGame.h"

unsigned headMenu();

int main() {
  inputKey InputKey;
  renderGame render;
  unsigned gameStatus(2);
  gameStatus = render.headMenu();

  if (gameStatus == 1) {  // Новая игра
    // inGameLogic game(InputKey, true);
    return 0;
  } else {
    if (gameStatus == 2) {
      return 0;
    }
  }
}
