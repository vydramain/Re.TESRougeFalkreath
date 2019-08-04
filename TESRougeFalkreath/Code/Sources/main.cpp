

#include "./inGameLogic.h"
#include "./inputKey.h"
#include "./renderGame.h"

unsigned headMenu();

int main() {
  inputKey InputKey;
  renderGame *renderMenu = new renderGame(false);
  unsigned gameStatus(0);
  gameStatus = renderMenu->headMenu();
  delete renderMenu;

  switch (gameStatus) {  // Новая игра
    case 1: {
      renderGame *renderPlay = new renderGame(true);
      inGameLogic game(InputKey, true);
      game.createPlayer(*renderPlay);
      renderPlay->clearALL();
      game.play(*renderPlay);

      delete renderPlay;
      return 0;
    }
    default: {
      return 0;
    }
  }
}
