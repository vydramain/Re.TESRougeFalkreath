//
// Created by vydra on 7/21/19.
//

#ifndef TESROUGEFALKREATH_CODE_HEADERS_LOGICPARTS_MAPS_H_
#define TESROUGEFALKREATH_CODE_HEADERS_LOGICPARTS_MAPS_H_

#include "./logicParts/LoadFile.h"


class Map {
 private:
  // const unsigned active_x1_=15, active_y1_=10, active_x2_=45, active_y2_=30;
  // Активная зона длействий игрока(для меньшего дергания экрана)

  LoadFile currentMap_;
  char **mapChar;
  int mapXSize_, mapYSize_;

  //bool loadMap();
  //void symColor( char mapSym);

 public:
  explicit Map(unsigned mapNumber);  // номер соответствующей локации
  ~Map();
  //void getSize(int &x, int &y);



  //////////////////////////////////////////////////////////////рендер
  //void renderMap(int xm, int ym);           //запрашивает координаты игрока
  //char getSymbol(int xM, int yM);           //возвращает символ из определённой координаты
};

#endif  // TESROUGEFALKREATH_CODE_HEADERS_LOGICPARTS_MAPS_H_
