#ifndef TESROUGEFALKREATH_CODE_HEADERS_INGAMEPARTS_LOGICCOMPONENTS_H_
#define TESROUGEFALKREATH_CODE_HEADERS_INGAMEPARTS_LOGICCOMPONENTS_H_

#include <controlComponents/inputCommand.h>
#include <controlComponents/myECS.h>
#include <inGameParts/logicComponents/items/septim.h>
#include <stdlib.h>
#include <time.h>
#include "controlComponents/playMap.h"
#include "inGameParts/logicComponents/item.h"
#include "inGameParts/logicComponents/npc.h"
#include "inGameParts/logicComponents/player.h"

class logicComponents {
 private:
  player* PLAYER_ = nullptr;
  playMap* MAP_ = nullptr;
  septim* COIN_ = nullptr;

  myECS* ECS_ = nullptr;

  bool logWindow = false;

 public:
  explicit logicComponents();
  ~logicComponents();

  bool createPlayer(char*, unsigned);  // Имя, Раса
  bool putPlayer(unsigned);
  bool loadPlayer();
  bool conditionPlayer(unsigned& X, unsigned& Y);
  bool conditionPlayer(unsigned& X, unsigned& Y, unsigned& Course);
  bool conditionPlayer(unsigned& X, unsigned& Y, unsigned& HP, unsigned& AP, unsigned& MP, unsigned& NATIONALITY, unsigned& STATUS,
                       char* NAME, unsigned& WALLET);

  bool loadMap(const unsigned&, const unsigned&, const unsigned&, char**);  // Имя карты, x, y, char

  bool createCoin();
  unsigned findCoin(unsigned X, unsigned Y);
  bool deleteCoin();

  bool createECS();

  void changeLogWindow(bool);
  void conditionLogWindow(bool&);

  void changeOldAct(unsigned);
  void conditionOldAct(unsigned&);

  void changeChangeArea(bool);
  void conditionChangeArea(bool&);

  void conditionEnd(bool&);

  playMap* secret() {
    return MAP_;
  }

  bool Update(const inputCommand_& containerCommand);
};

#endif  // TESROUGEFALKREATH_CODE_HEADERS_INGAMEPARTS_LOGICCOMPONENTS_H_
