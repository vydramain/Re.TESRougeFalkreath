//
// Created by vydra on 7/28/19.
//

#ifndef TESROUGEFALKREATH_WORLD_H
#define TESROUGEFALKREATH_WORLD_H

#include "logicParts/World/Map.h"

class World {
 private:
  Map currentMap_;

 public:
  explicit World(const Map &inputMap) : currentMap_(inputMap) {}

};



#endif //TESROUGEFALKREATH_WORLD_H
