
#include <BearLibTerminal.h>
#include "./MainMenu.cpp"
#include "./inputKey.h"
#include "./player.h"
#include "./collisio.h"
#include "./Maps.h"
#include "./hud.h"


int main() {
  unsigned gameStatus;
  gameStatus= mainMenu();

  if(gameStatus== 1){
    return 1;
  } else{
    if(gameStatus== 2){
      return 0;
    }
  }
}