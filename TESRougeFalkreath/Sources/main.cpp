
#include <iostream>
#include <BearLibTerminal.h>
#include "../Includes/inputKey/inputKey.h"
#include "../Includes/Units/Player/player.h"


int main() {
    inputKey InputKey;
    player Player(InputKey,1,1);

    terminal_open();
    terminal_refresh();

    while(true) {
        terminal_clear();
        InputKey.Update();
        Player.Update();
        terminal_refresh();

        if(InputKey.IsExit() || InputKey.IsButtonEsc()){
            break;
        }
    }

    return 0;
}