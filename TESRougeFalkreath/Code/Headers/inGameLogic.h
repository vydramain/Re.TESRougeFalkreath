//
// Created by vydra on 7/23/19.
//

#ifndef TESROUGEFALKREATH_CODE_HEADERS_INGAMELOGIC_H_
#define TESROUGEFALKREATH_CODE_HEADERS_INGAMELOGIC_H_

#define FRAMES_PER_SECOND_ 0.008

#include <inputKey.h>
#include <ctime>
#include "./renderGame.h"
#include "logicParts/npcs.h"
#include "logicParts/item.h"
#include "logicParts/map.h"
#include "logicParts/player.h"

class inGameLogic {
 private:
  inputKey &InputKey_;
  renderGame Render;
  player GG_;
  map CurrentMap_;
  npcs *arrayNpcs_;
  npcs Norman_;

  //  items CurrentItems_;

  bool movePlayer();
  void actionPlayer();
  void Update();

 public:
  explicit inGameLogic(inputKey &InputKey, bool NewGame);
  virtual ~inGameLogic() = default;

  void createPlayer(unsigned x, unsigned y);
  void createNpc(const char *Name, unsigned Nationality, unsigned x, unsigned y);
  void createNpc(const char *Name, unsigned Nationality, unsigned x, unsigned y, unsigned current);  // Для будущего
  void locatePlayer(unsigned x, unsigned y);

  void play();
};

#endif  // TESROUGEFALKREATH_CODE_HEADERS_INGAMELOGIC_H_
