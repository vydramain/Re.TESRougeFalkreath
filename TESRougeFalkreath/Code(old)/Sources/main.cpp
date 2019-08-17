

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
      game.createPlayer(49, 20);
      game.createNpc("Асгольд", 2, 43, 9);

      game.play();

      return 0;
    }
    default: {
      return 0;
    }
  }
}
