//
// Created by vydra on 7/15/19.
//

#ifndef TESROUGEFALKREATH_CODE_HEADERS_LOGICPARTS_PLAYER_H_
#define TESROUGEFALKREATH_CODE_HEADERS_LOGICPARTS_PLAYER_H_

#include <BearLibTerminal.h>
#include "./LoadFile.h"

class player {
 private:
  char naked = 'i';  // игрок без брони
  LoadFile currentSave_;
  unsigned screenX_ = 30, screenY_ = 20;  // для отображения на экране
  unsigned mapX = 0, mapY = 0;            // для размещения на карте

  char *playerName_;
  unsigned playerNation_;  // Расы:
                           // 1. Норд
                           // 2. Бретон
                           // 3. Редгард
                           // 4. Имперец
                           // 5. Высокий эльф
                           // 6. Тёмный эльф
                           // 7. Лесной эльф
                           // 8. Орк
                           // 9. Аргонианин
                           // 10. Каджит
  unsigned HP;
  unsigned MP;
  unsigned AP;
  unsigned SP;
  unsigned course = 1;  //  направление в котором последний раз двигался персонаж
                        //  0 -вврех,
                        //  1 -влево,
                        //  2 -вправо,
                        //  3 -вниз.

 public:
  void startPlayer(bool category);
  void pullName(char *Name);
  void pullNation(unsigned nation);
  void pullTerrain(unsigned xm, unsigned ym);
  // void getLocation(unsigned &x, unsigned &y);
  // void putTerrain(unsigned xm, unsigned ym);

  ////////////////////////////////////////////////////////////// рендер
  // void renderPlayer();
};

#endif  // TESROUGEFALKREATH_CODE_HEADERS_LOGICPARTS_PLAYER_H_
