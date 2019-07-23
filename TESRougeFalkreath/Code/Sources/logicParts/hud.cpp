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
  terminal_print(62,10,"Цель:");
  terminal_print(62,11,"Добыть тяжёлую");
  terminal_print(62,12,"броню!");




    if (dialog == true) {
              for(int ii=25;ii<40;ii++){
          for(int i=0;i<40;i++){
            terminal_put(i,ii,' ');
          }
        }
      terminal_print(0, 25, "________________________________________");
        for (unsigned i(0); i < 15; i++) {
            terminal_print(40, 26 + i, "|");
        }
        if(askDoorMark){
          askDoor();
        }
        if(askArmorMark){
          askArmor();
        }
    }

}

bool hud::askDoor() {
    dialog= true;
    terminal_color(0xFFFFFFFF);
    terminal_print(2,30,"Открыть дверь?");
    return true;
}
bool hud::askArmor(){
  dialog= true;
  terminal_color(0xFFFFFFFF);
  terminal_print(2,30,"Найдена: Тяжелая броня.");
terminal_color(0x99FFFFFF);
terminal_print(2,31,"(у вас недостаточно характеристик,");
terminal_print(2,32, "чтобы её взять)");
  return true;
}