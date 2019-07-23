//
// Created by vydra on 7/23/19.
//

#include "../Headers/renderGame.h"

/*bool Render::goRender(Maps map, player gg, hud interface) {
    terminal_clear();
    unsigned xm, ym;
    gg.getTerrain(xm, ym);
    map.printMap(xm, ym);
    interface.renderHud();
    gg.render();
    terminal_color(0xffffffff);


    terminal_refresh();
    return true;
}

void player::render() { // рендер персонажа
    if(x_m<30){
      x_= x_m;
    }
    if(y_m<20){
      y_= y_m;
    }
    if(x_m>){
      x_= x_m;
    }
    if(x_m>30){
      x_= x_m;
    }

    terminal_color(0xfffdff70);
    terminal_put_ext(x_, y_, 0 , 0,symbol); //, 0xaaFFAAff);

}

void Maps::printMap(int xm, int ym) { // рендер карты
    bool mark;
    if(x<15 || x>30 || y<10 ||y>30){
      mark= true; // сдвинуть камеру надо
    }


    for (int ii(0); ii < 40; ii++) {
        for (int i(0); i < 60; i++) {
            terminal_color(0xff989898);
            //printf("%c", mapChar[ym-20+ii][xm-30+i]);
            terminal_put(i, ii, mapChar[ym-20 + ii][xm-30+i]);




        }
        printf("\n");
    }
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

*/