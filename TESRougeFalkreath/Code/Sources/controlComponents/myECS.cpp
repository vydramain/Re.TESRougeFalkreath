//
// Created by vydra on 8/21/19.
//

#include "controlComponents/myECS.h"

myECS::myECS() {
  PLAYER_ = nullptr;
  MAP_ = nullptr;
}

myECS::myECS(playMap* Map, player* Player, septim* Coin) {
  MAP_ = Map;
  PLAYER_ = Player;
  COIN_ = Coin;
}

myECS::~myECS() {
  PLAYER_ = nullptr;
  MAP_ = nullptr;
}

bool myECS::EcsUpdate(inputCommand_ containerCommand) {
  unsigned move, act;
  containerCommand.moveOutCommand(move);
  containerCommand.actOutCommand(act);
  containerCommand.clearCommand();
  if (act) {
    PLAYER_->changeOldAct(act);
  }

  unsigned playerX, playerY, playerHP, playerAP, playerMP, playerCourse, playerStatus, wallet;
  PLAYER_->viewLocation(playerX, playerY);
  PLAYER_->viewPoints(playerHP, playerAP, playerMP);
  PLAYER_->viewCourse(playerCourse);
  PLAYER_->viewStatus(playerStatus);
  PLAYER_->viewCoinsCount(wallet);

  char layer0, layer1, layer2, layer3;
  MAP_->pullKnot(playerX, playerY, layer0, layer1, layer2, layer3);

  unsigned coinPrice(0);
  if (layer3 == '$') {
    unsigned coinX, coinY;
    for (unsigned i(0); i < 16; i++) {
      COIN_[i].conditionPlaceSeptim(coinX, coinY);
      if (coinX == playerX && coinY == playerY) {
        COIN_[i].conditionPriceSeptim(coinPrice);
      }
    }
    PLAYER_->changeCoinsCount(wallet + coinPrice);
    MAP_->changeKnot3(playerX, playerY, ' ');
  }

  if (move != 0) {
    switch (move) {
      case 1: {
        PLAYER_->changeCourse(0);
        MAP_->pullKnot(playerX, playerY - 1, layer0, layer1, layer2, layer3);
        if ((layer0 == ' ' || layer0 == '.' || layer0 == 'L') && layer1 == ' ' && layer2 == ' ') {
          PLAYER_->changeLocation(playerX, playerY -= 1);
        }
        break;
      }
      case 2: {
        PLAYER_->changeCourse(1);
        MAP_->pullKnot(playerX, playerY + 1, layer0, layer1, layer2, layer3);
        if ((layer0 == ' ' || layer0 == '.' || layer0 == 'L' || layer0 == '_') && layer1 == ' ' && layer2 == ' ') {
          char layerAdd;
          MAP_->pullKnot0(playerX, playerY, layerAdd);
          if (layerAdd != '_') {
            PLAYER_->changeLocation(playerX, playerY += 1);
          }
        }
        break;
      }
      case 3: {
        PLAYER_->changeCourse(2);
        MAP_->pullKnot(playerX - 1, playerY, layer0, layer1, layer2, layer3);
        if ((layer0 == ' ' || layer0 == '.' || layer0 == 'L' || layer0 == '_') && layer1 == ' ' && layer2 == ' ') {
          PLAYER_->changeLocation(playerX -= 1, playerY);
        }
        break;
      }
      case 4: {
        PLAYER_->changeCourse(3);
        MAP_->pullKnot(playerX + 1, playerY, layer0, layer1, layer2, layer3);
        if ((layer0 == ' ' || layer0 == '.' || layer0 == 'L' || layer0 == '_') && layer1 == ' ' && layer2 == ' ') {
          PLAYER_->changeLocation(playerX += 1, playerY);
        }
        break;
      }
      default: {
        break;
      }
    }
    lastReturn_ = false;
    return false;
  } else {
    if (act != 0) {
      switch (playerCourse) {
        case 0: {
          playerY -= 1;
          break;
        }
        case 1: {
          playerY += 1;
          break;
        }
        case 2: {
          playerX -= 1;
          break;
        }
        case 3: {
          playerX += 1;
          break;
        }
        default: {
          break;
        }
      }
      MAP_->pullKnot0(playerX, playerY, layer0);
      switch (act) {
        case 1: {
          if (layer0 == '<' || layer0 == '>' || layer0 == 'v' || layer0 == '^') {
            PLAYER_->changeLocation(playerX, playerY);
          }
          if (layer0 == 'Z') {
            PLAYER_->changeChangeArea(true);
          }
          if (layer0 == 'Q') {
            PLAYER_->changeEndGame(true);
          }
          lastReturn_ = false;
          return false;
        }
        case 5: {
          lastReturn_ = true;
          return true;
        }
        case 6: {
          lastReturn_ = true;
          return true;
        }
        default: {
          lastReturn_ = false;
          return false;
        }
      }
    } else {
      if (lastReturn_) {
        return true;
      } else {
        return false;
      }
    }
  }
}