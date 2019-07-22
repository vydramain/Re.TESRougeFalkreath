//
// Created by vydra on 7/21/19.
//

#ifndef TESROUGEFALKREATH_CODE_INCLUDE_MAPS_H_
#define TESROUGEFALKREATH_CODE_INCLUDE_MAPS_H_

#include <BearLibTerminal.h>
#include <stdio.h>
#include "./player.h"

class Maps {
 private:
  FILE *map;
  char **mapChar;
  unsigned x_, y_;

  bool loadMap();

 public:
  Maps(unsigned in);

  void printMap(unsigned x, unsigned y);
};

#endif  // TESROUGEFALKREATH_CODE_INCLUDE_MAPS_H_
