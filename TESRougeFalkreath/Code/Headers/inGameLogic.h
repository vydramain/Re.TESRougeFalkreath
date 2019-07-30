//
// Created by vydra on 7/23/19.
//

#ifndef TESROUGEFALKREATH_CODE_HEADERS_INGAMELOGIC_H_
#define TESROUGEFALKREATH_CODE_HEADERS_INGAMELOGIC_H_

#include <inputKey.h>
#include "./renderGame.h"
#include "logicParts/map.h"
#include "logicParts/player.h"

class inGameLogic {
 private:
  inputKey &InputKey_;
  player GG_;
  map CurrentMap_;

  bool movePlayer(renderGame &Render);
  void actionPlayer(renderGame &Render);
  void Update(renderGame &Render);

 public:
  explicit inGameLogic(inputKey &InputKey, bool NewGame);
  virtual ~inGameLogic() = default;
  void createPlayer(renderGame &Render);
  void play(renderGame &Render);
};

#endif  // TESROUGEFALKREATH_CODE_HEADERS_INGAMELOGIC_H_
