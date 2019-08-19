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

  bool loadMap(const unsigned&, const unsigned&, const unsigned&, char**);  // Имя карты, x, y, char


};

#endif  // TESROUGEFALKREATH_CODE_HEADERS_INGAMEPARTS_LOGICCOMPONENTS_H_
