//
// Created by vydra on 7/15/19.
//

#ifndef TESROUGEFALKREATH_CODE_HEADERS_LOGICPARTS_PLAYER_H_
#define TESROUGEFALKREATH_CODE_HEADERS_LOGICPARTS_PLAYER_H_

#include <BearLibTerminal.h>
#include <string.h>
#include "./item.h"
#include "./loadFile.h"

class player {
 private:
  loadFile currentSave_;

 public:
  char naked = 'i';  // игрок без брони

  unsigned screenX_ = 30, screenY_ = 20;  // для отображения на экране
  int mapX_ = 0, mapY_ = 0;        // для размещения на карте
  unsigned course = 1;  //  направление в котором последний раз двигался персонаж
                        // 0 -вврех,
                        // 1 -влево,
                        // 2 -вправо,
                        // 3 -вниз.

  bool confirmAsk_ = false;
  unsigned question_ = 0;  // 0 - Нет вопроса
                           // 1 - Открыть Дверь?
                           // 2 - Спрятаться в зелени?
                           // 3 - Выйти из зелени?
                           // 4 - Отправиться в Восточный Лес?
                           // 5 - Диалог с NPC
                           // 10 - Надеть броню?

  bool explanationAsk_ = false;
  unsigned explanation_ = 0;  // 0 - Нет объяснения
                              // 1 - Это дверь. Похоже, из многовековой ели.
                              // 2 - Это хвойное растение. Похоже на ель.
                              // 3 - Камень. Мне через него не перебраться.
                              // 4 - Гладкая каменная стена... ...из хорошего булыжника.
                              // 5 - Пшеница... Несозревшая...
                              // 6 - Ствол... Просто ствол дерева...
                              // 7 - Забор деревянный. Добротный.
                              // 8 - Могила...     ...впервые вижу эти руны... ...скорее всего они из Атморы.
                              // 9 - Вода.
                              // 10 - Норман?

  char playerName_[24];
  unsigned HP_;
  unsigned MP_;
  unsigned AP_;
  unsigned SP_;
  unsigned status_ = 0;  // Cостояние игрока:
                         // 0. Мёртв
                         // 1. Обычное состояние
                         // 2. Спрятался

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
  int attack_;
  float block_;
  unsigned armorSlot_;
  unsigned weaponSlot_;

  unsigned quest = 0;  // Задания:
                        // 0. - Нет заданий
                        // 1. - Найти пасхалку!

  player();
  ~player();
  void startPlayer(bool category);
  void pullTerrain(unsigned xm, unsigned ym);
  //  void putItem(items *Item);
};

#endif  // TESROUGEFALKREATH_CODE_HEADERS_LOGICPARTS_PLAYER_H_
