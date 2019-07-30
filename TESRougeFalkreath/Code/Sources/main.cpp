
#include <BearLibTerminal.h>
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

  if (gameStatus == 1) {  // Новая игра
    renderGame *renderPlay = new renderGame(true);
    inGameLogic game(InputKey, true);
    game.createPlayer(*renderPlay);
    game.play(*renderPlay);

    delete renderPlay;
    return 0;
  } else {
    if (gameStatus == 5 || gameStatus == 0) {
      return 0;
    }
  }
}
