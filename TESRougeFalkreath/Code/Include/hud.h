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
  Maps map;

  void renderHud(){
    for(unsigned i(0); i<40; i++){
      terminal_print(60, i, "|");
    }
    if(dialog == true){
      terminal_print(0,25, "________________________________________");
      for(unsigned i(0); i<15; i++){
        terminal_print(40, 26+i, "|");
      }
    }
  }

  bool renderMap(){
    return false;
  }
 public:
    hud() {
      dialog= false;
    }


};



#endif //TESROUGEFALKREATH_HUD_H
