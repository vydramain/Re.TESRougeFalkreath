#ifndef TESROUGEFALKREATH_CODE_HEADERS_INGAMEPARTS_LOGICCOMPONENTS_NPCMIND_H_
#define TESROUGEFALKREATH_CODE_HEADERS_INGAMEPARTS_LOGICCOMPONENTS_NPCMIND_H_

#include "./Enemy.h"

class NpcMind {
 private:
  unsigned *coordinateEnemiesX;
  unsigned *coordinateEnemiesY;

  unsigned enemiesAmount;

 public:
  explicit NpcMind();
  ~NpcMind();

  void checkArea(Enemy currentEnemy);
};

#endif  // TESROUGEFALKREATH_CODE_HEADERS_INGAMEPARTS_LOGICCOMPONENTS_NPCMIND_H_
