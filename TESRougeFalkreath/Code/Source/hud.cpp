//
// Created by vydra on 7/21/19.
//

#include "./hud.h"
#include <BearLibTerminal.h>
#include "./Maps.h"

hud::hud(unsigned in) {
  dialog = false;
  Maps map(unsigned in);
}

void hud::renderHud() {
  for (unsigned i(0); i < 40; i++) {
    terminal_print(60, i, "|");
  }
  if (dialog == true) {
    terminal_print(0, 25, "________________________________________");
    for (unsigned i(0); i < 15; i++) {
      terminal_print(40, 26 + i, "|");
    }
  }
}
bool hud::renderMap(unsigned x, unsigned y) {


}