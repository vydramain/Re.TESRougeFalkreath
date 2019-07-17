
#include <BearLibTerminal.h>
#include "inputKey.h"
#include "player.h"
#include "collisio.h"
#include "Maps/JarlLonghouse.h"

void render();

int main() {
  terminal_set("window.title=TES Falkreath");


  inputKey InputKey;
  player Player(InputKey, 16, 22);
  collisio OutWalls(2,1,31,23);
  collisio In1Walls(2,1,11,6);
  collisio In21Walls(21,1,31,6);
  collisio In3Walls(2,15,11,23);
  collisio In4Walls(21,15,31,23);
  collisio mini1Walls(11,7,11,7);
  collisio mini2Walls(22,7,22,7);
  collisio mini3Walls(11,9,11,14);
  collisio mini4Walls(22,9,22,14);


  terminal_open();

  terminal_refresh();

  while (true) {
    terminal_clear();

    InputKey.Update();
    render();
    Player.Update();
    terminal_refresh();

    if (InputKey.IsExit() || InputKey.IsButtonEsc()) {
      break;
    }
  }

  return 0;
}




void render(){
  terminal_print(11,1,          "808080808080");
  terminal_print(11,2,          "8          0");
  terminal_print(11,3,          "8          0");
  terminal_print(11,4,          "8          0");
  terminal_print(11,5,          "8          0");
  terminal_print(2,6,  "0808080808          0808080808");
  terminal_print(2,7,  "0        8          0        8");
  terminal_print(2,8,  "0                            8");
  terminal_print(2,9  ,"0                            8");
  terminal_print(2,10, "0        8          0        8");
  terminal_print(2,11 ,"0        8          0        8");
  terminal_print(2,12 ,"0        8          0        8");
  terminal_print(2,13 ,"0        8          0        8");
  terminal_print(2,14 ,"0        8          0        8");
  terminal_print(2,15, "0808080808          0808080808");
  terminal_print(11,16,         "8          0");
  terminal_print(11,17,         "8          0");
  terminal_print(11,18,         "8          0");
  terminal_print(11,19,         "8          0");
  terminal_print(11,20,         "8          0");
  terminal_print(11,21,         "8          0");
  terminal_print(11,22,         "8          0");
  terminal_print(11,23,         "80808--08080");
}