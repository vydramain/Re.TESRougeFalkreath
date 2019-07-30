//
// Created by vydra on 7/15/19.
//

#ifndef TESROUGEFALKREATH_CODE_HEADERS_LOGICPARTS_PLAYER_H_
#define TESROUGEFALKREATH_CODE_HEADERS_LOGICPARTS_PLAYER_H_

#include <BearLibTerminal.h>
#include <string.h>
#include "./loadFile.h"

class player {
 private:
  loadFile currentSave_;

 public:
  char naked = 'i';  // игрок без брони

  unsigned screenX_ = 0, screenY_ = 0;  // для отображения на экране
  unsigned mapX_ = 0, mapY_ = 0;        // для размещения на карте
  unsigned course = 1;  //  направление в котором последний раз двигался персонаж
                        // 0 -вврех,
                        // 1 -влево,
                        // 2 -вправо,
                        // 3 -вниз.

  char playerName_[12];
  unsigned status_;
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

  player();
  void startPlayer(bool category);
  void pullTerrain(unsigned xm, unsigned ym);
};

#endif  // TESROUGEFALKREATH_CODE_HEADERS_LOGICPARTS_PLAYER_H_
