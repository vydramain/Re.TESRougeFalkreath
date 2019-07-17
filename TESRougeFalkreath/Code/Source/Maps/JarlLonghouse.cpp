//
// Created by vydra on 7/17/19.
//

#include "Maps/JarlLonghouse.h"
#include <BearLibTerminal.h>
#include "collisio.h"

void JarlLonghouse::Render(){
  terminal_print(11,1,          "808080808080");
  terminal_print(11,2,          "8          0");
  terminal_print(11,3,          "8          0");
  terminal_print(11,4,          "8          0");
  terminal_print(11,5,          "8          0");
  terminal_print(2,6,  "0808080808          0808080808");
  terminal_print(2,7,  "0        8          0        8");
  terminal_print(2,8,  "0                            8");
  terminal_print(2,9  ,"0                            8");
  terminal_print(2,10, "0        8          0        8");
  terminal_print(2,11 ,"0        8          0        8");
  terminal_print(2,12 ,"0        8          0        8");
  terminal_print(2,13 ,"0        8          0        8");
  terminal_print(2,14 ,"0        8          0        8");
  terminal_print(2,15, "0808080808          0808080808");
  terminal_print(11,16,         "8          0");
  terminal_print(11,17,         "8          0");
  terminal_print(11,18,         "8          0");
  terminal_print(11,19,         "8          0");
  terminal_print(11,20,         "8          0");
  terminal_print(11,21,         "8          0");
  terminal_print(11,22,         "8          0");
  terminal_print(11,23,         "80808--08080");
}

void JarlLonghouse::Collisions() {


}