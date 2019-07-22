
#include <BearLibTerminal.h>
#include "inputKey.h"
#include "player.h"
#include "collisio.h"
#include "Maps.h"
#include "hud.h"


int main() {
  hud hd;
  inputKey InputKey;
  player Player(InputKey, 30, 20);

  terminal_open();
  terminal_set("window: title='TES Falkreath', size=80x40; font: ./Fonts/Ubuntu-C.ttf, size=12");

  terminal_refresh();

  while (true) {
    terminal_clear();


    InputKey.Update();
    Player.Update();

    terminal_refresh();

    if (InputKey.IsExit()) {
      break;
    }
  }

  return 0;
}