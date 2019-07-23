//
// Created by vydra on 7/21/19.
//

#include "../../Headers/logicParts/hud.h"
#include <BearLibTerminal.h>
#include "../../Headers/logicParts/Maps.h"

hud::hud(player GG) {
  dialog = false;
}
void hud::renderHud() { // рендер худа
    for (unsigned i(0); i < 40; i++) {
        terminal_print(60, i, "|");
    }
    terminal_print(62,1,"Имя:");
    terminal_print(62,2,"Расса:");
    terminal_print(62,3,"Статус:");
    terminal_print(62,4,"ОЗ:");
    terminal_print(62,5,"OМ:");
    terminal_print(62,6,"ОД:");
    terminal_print(62,7,"ОС:");

    if (dialog == true) {
        terminal_print(0, 25, "________________________________________");
        for (unsigned i(0); i < 15; i++) {
            terminal_print(40, 26 + i, "|");
        }
    }
}