//
// Created by vydra on 7/21/19.
//

#ifndef TESROUGEFALKREATH_CODE_HEADERS_LOGICPARTS_MAP_H_
#define TESROUGEFALKREATH_CODE_HEADERS_LOGICPARTS_MAP_H_

#include <string.h>
#include "logicParts/loadFile.h"

class map {
 private:
  // const unsigned active_x1_=15, active_y1_=10, active_x2_=45, active_y2_=30;
  // Активная зона длействий игрока(для меньшего дергания экрана)

  loadFile currentMap_;

 public:
  bool errsMap = false;
  char mapName_[10];
  char** mapChar_;
  int mapXSize_, mapYSize_;

  explicit map();  // номер соответствующей локации
  virtual ~map();
  map& operator=(const map& old);

  bool choiseMap(unsigned mapNumber);
  char getSymbol(int xGG, int yGG);
};

#endif  // TESROUGEFALKREATH_CODE_HEADERS_LOGICPARTS_MAP_H_
