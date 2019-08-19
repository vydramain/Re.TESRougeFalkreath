#ifndef TESROUGEFALKREATH_CODE_HEADERS_INGAMEPARTS_LOGICCOMPONENTS_H_
#define TESROUGEFALKREATH_CODE_HEADERS_INGAMEPARTS_LOGICCOMPONENTS_H_

#include "controlComponents/playMap.h"
#include "inGameParts/logicComponents/item.h"
#include "inGameParts/logicComponents/npc.h"
#include "inGameParts/logicComponents/player.h"

class logicComponents {
 private:
  player* PLAYER_ = nullptr;
  playMap* MAP_ = nullptr;

 public:
  explicit logicComponents();
  ~logicComponents();

  bool createPlayer(char*, unsigned);  // Имя, Раса
  bool loadPlayer();
  bool conditionPlayer(unsigned& X, unsigned& Y);
  bool conditionPlayer(unsigned& X, unsigned& Y, unsigned& HP, unsigned& AP, unsigned& MP, unsigned& NATIONALITY, unsigned& STATUS, char* NAME);
  bool actPLayer(unsigned typeACT, unsigned ACT);  // Тип команды, команда
                                                   // Тип 0 - бездействие
                                                   // Тип 1 перемещение: 0-вверх, 1-вниз, 2-влево, 3-вправо
                                                   // Тип 2 действие: 0-действие, 1-осмотр, 2-диалог, 3-физическая атака,
                                                   // 4-магическая атака, 5-карабкаться, 6-инвентарь

  bool loadMap(const unsigned&, const unsigned&, const unsigned&, char**);  // Имя карты, x, y, char

  playMap* secret() {
    return MAP_;
  }

  bool Update(unsigned typeACT, unsigned ACT);
};

#endif  // TESROUGEFALKREATH_CODE_HEADERS_INGAMEPARTS_LOGICCOMPONENTS_H_
