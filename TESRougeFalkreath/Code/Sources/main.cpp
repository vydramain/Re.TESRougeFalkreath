
#include <stdio.h>
#include "inGameParts/renderGame.h"

int main() {
  renderGame j(1);
  // j.mainMenu(0);
  terminal_print(10,10,"e[q");
  terminal_refresh();
  while(true){}
  return 0;
}
