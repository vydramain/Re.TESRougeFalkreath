//
// Created by vydra on 7/28/19.
//

#ifndef TESROUGEFALKREATH_CODE_HEADERS_LOGICPARTS_WORLD_H_
#define TESROUGEFALKREATH_CODE_HEADERS_LOGICPARTS_WORLD_H_

#include "logicParts/World/Map.h"

class World {
 public:
  explicit World() {}
  virtual ~World();

  void loadWorld(unsigned mapNumber);
};

#endif  // TESROUGEFALKREATH_CODE_HEADERS_LOGICPARTS_WORLD_H_
