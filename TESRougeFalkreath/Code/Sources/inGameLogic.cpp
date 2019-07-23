//
// Created by vydra on 7/23/19.
//

#include "../Headers/inGameLogic.h"
#include "./logicParts/hud.h"

void inGameLogic::update() {

}
void inGameLogic::inGameFT() {  //первый запуск

    Maps startMap(0);
    startMap.getSize(mapX, mapY);
    player GG(40, 20);
    hud HUD(GG);
    render.goRender(startMap,GG,HUD);
  while(true) {}

}