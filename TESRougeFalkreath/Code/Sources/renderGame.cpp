//
// Created by vydra on 7/23/19.
//

#include "../Headers/renderGame.h"

void renderGame::goRender(Maps &map, player &gg, hud &interface) {
    terminal_clear();
    unsigned xm, ym;
    gg.getTerrain(xm, ym);
    map.renderMap(xm, ym);
    gg.renderPlayer();
    terminal_color(0xffffffff);
    interface.renderHud();

    terminal_refresh();

}



