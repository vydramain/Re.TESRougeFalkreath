//
// Created by vydra on 7/23/19.
//

#include "Render.h"
#include <BearLibTerminal.h>
#include "logicParts/World/Map.h"
#include "../../Code/Headers/logicParts/hud.h"
#include "../../Code/Headers/logicParts/player.h"

bool Render::goRender(Maps map, player gg, hud interface) {
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