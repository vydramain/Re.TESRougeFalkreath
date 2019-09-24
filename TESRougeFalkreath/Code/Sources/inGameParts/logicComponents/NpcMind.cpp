#include "inGameParts/logicComponents/NpcMind.h"

NpcMind::NpcMind() {
  this->enemiesAmount = 0;
  this->coordinateEnemiesX = new unsigned[13];
  this->coordinateEnemiesY = new unsigned[13];

  for (unsigned i(0); i < 13; i++) {
    this->coordinateEnemiesX[i] = 0;
    this->coordinateEnemiesY[i] = 0;
  }
}

NpcMind::~NpcMind() {
  delete this->coordinateEnemiesX;
  delete this->coordinateEnemiesY;
}

void NpcMind::checkArea(Enemy currentEnemy) {
  unsigned currentX = currentEnemy.viewLocationX();
  unsigned currentY = currentEnemy.viewLocationY();
  unsigned currentCourse = currentEnemy.viewCourse();

  switch (currentCourse) {
    case 0: {
      for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; ++j) {
          currentX+=i;
          currentY+=j;
        }
      }
    }
    default: {
    }
  }
}
