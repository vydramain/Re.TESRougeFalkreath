//
// Created by vydra on 7/21/19.
//

#ifndef TESROUGEFALKREATH_CODE_INCLUDE_HUD_H_
#define TESROUGEFALKREATH_CODE_INCLUDE_HUD_H_

#include <BearLibTerminal.h>
#include "Maps.h"

class hud {
 private:
  bool dialog;

  bool renderMap();
  void renderHud();

 public:
  hud(unsigned in);
  void render();
};

#endif  // TESROUGEFALKREATH_CODE_INCLUDE_HUD_H_
