//
// Created by vydra on 7/21/19.
//

#ifndef TESROUGEFALKREATH_CODE_HEADERS_LOGICPARTS_WORLD_MAP_H_
#define TESROUGEFALKREATH_CODE_HEADERS_LOGICPARTS_WORLD_MAP_H_

#include <string.h>
#include "./logicParts/LoadFile.h"

class Map {
 private:
  // const unsigned active_x1_=15, active_y1_=10, active_x2_=45, active_y2_=30;
  // Активная зона длействий игрока(для меньшего дергания экрана)

  LoadFile currentMap_;
  bool errsMap = false;
  char* mapName_;
  char** mapChar_;
  int mapXSize_, mapYSize_;

 public:
  explicit Map(unsigned mapNumber);  // номер соответствующей локации
  virtual ~Map();
  Map& operator=(const Map& old);
};

#endif  // TESROUGEFALKREATH_CODE_HEADERS_LOGICPARTS_WORLD_MAP_H_
