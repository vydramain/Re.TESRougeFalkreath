

#include "./inGameLogic.h"
#include "./inputKey.h"
#include "./renderGame.h"

unsigned headMenu();

int main() {
  inputKey InputKey;
  renderGame *renderMenu = new renderGame(0);
  unsigned gameStatus(0);
  gameStatus = renderMenu->headMenu();
  delete renderMenu;

  switch (gameStatus) {  // Новая игра
    case 1: {
      inGameLogic game(InputKey, true);
      game.createPlayer(30, 20);
      game.play();
      return 0;
    }
    default: {
      return 0;
    }
  }
}
