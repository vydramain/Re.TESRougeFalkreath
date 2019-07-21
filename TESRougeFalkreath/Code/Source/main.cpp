
#include <BearLibTerminal.h>
#include "inputKey.h"
#include "player.h"
#include "collisio.h"
#include "Maps/JarlLonghouse.h"

void render();

int main() {
  terminal_set("window: title='TES Falkreath', size=80x25; font: ./Ubuntu-R.ttf");
  inputKey InputKey;
  player Player(InputKey, 1, 1);


  terminal_open();

  terminal_refresh();

  while (true) {
    terminal_clear();

      InputKey.Update();
    Player.Update();
    terminal_refresh();

    if (InputKey.IsExit() || InputKey.IsButtonEsc()) {
      break;
    }
  }

  return 0;
}