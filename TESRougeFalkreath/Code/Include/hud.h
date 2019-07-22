//
// Created by vydra on 7/21/19.
//

#ifndef TESROUGEFALKREATH_HUD_H
#define TESROUGEFALKREATH_HUD_H

#include <BearLibTerminal.h>
#include "Maps.h"

class hud {
 private:

  bool dialog;

  void renderHud();

  bool renderMap();

 public:
  hud(unsigned in);
};

#endif  // TESROUGEFALKREATH_HUD_H
