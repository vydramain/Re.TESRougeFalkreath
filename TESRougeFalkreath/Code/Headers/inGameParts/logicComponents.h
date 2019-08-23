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
  unsigned conditionPlayerX();
  unsigned conditionPlayerY();
  unsigned conditionPlayerHP();
  unsigned conditionPlayerAP();
  unsigned conditionPlayerMP();
  unsigned conditionPlayerNATIONALITY();
  unsigned conditionPlayerSTATUS();
  unsigned conditionPlayerWALLET();
  unsigned conditionPlayerCOURSE();
  char* conditionPlayerNAME();

  bool loadMap(const unsigned&, const unsigned&, const unsigned&, char**);  // Имя карты, x, y, char

  bool createCoin();
  unsigned findCoin(unsigned X, unsigned Y);
  bool deleteCoin();

  bool createECS();

  void changeLogWindow(bool Log);
bool  conditionLogWindow();

  void changeOldAct(unsigned IN);
  unsigned conditionOldAct();

  void changeChangeArea(bool IN);
  bool conditionChangeArea();

  bool conditionEnd();

  playMap* secret() {
    return MAP_;
  }

  bool Update(const inputCommand_& containerCommand);
};

#endif  // TESROUGEFALKREATH_CODE_HEADERS_INGAMEPARTS_LOGICCOMPONENTS_H_
