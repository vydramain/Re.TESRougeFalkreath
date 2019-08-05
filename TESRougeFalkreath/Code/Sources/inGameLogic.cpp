//
// Created by vydra on 7/23/19.
//

#include "../Headers/inGameLogic.h"

void inGameLogic::actionPlayer() {
  int xGG_m, yGG_m;  // Дополнительные маркеры
  if (GG_.course == 0) {
    xGG_m = GG_.mapX_;
    yGG_m = GG_.mapY_ - 1;
  }
  if (GG_.course == 3) {
    xGG_m = GG_.mapX_;
    yGG_m = GG_.mapY_ + 1;
  }
  if (GG_.course == 1) {
    yGG_m = GG_.mapY_;
    xGG_m = GG_.mapX_ - 1;
  }
  if (GG_.course == 2) {
    yGG_m = GG_.mapY_;
    xGG_m = GG_.mapX_ + 1;
  }

  if (InputKey_.IsButtonE()) {
    if (CurrentMap_.getSymbol(xGG_m, yGG_m) == 'v' || CurrentMap_.getSymbol(xGG_m, yGG_m) == '^' ||
        CurrentMap_.getSymbol(xGG_m, yGG_m) == '<' || CurrentMap_.getSymbol(xGG_m, yGG_m) == '>') {
      if (GG_.confirmAsk_) {
        GG_.mapX_ = xGG_m;
        GG_.mapY_ = yGG_m;
        GG_.confirmAsk_ = false;
        GG_.question_ = 0;
      } else {
        GG_.confirmAsk_ = true;
        GG_.question_ = 1;
      }
    } else {
      if ((CurrentMap_.getSymbol(xGG_m, yGG_m) == ';' || CurrentMap_.getSymbol(xGG_m, yGG_m) == '+' ||
           CurrentMap_.getSymbol(xGG_m, yGG_m) == '-' || CurrentMap_.getSymbol(xGG_m, yGG_m) == '?' ||
           CurrentMap_.getSymbol(xGG_m, yGG_m) == ':' || CurrentMap_.getSymbol(xGG_m, yGG_m) == 'J' ||
           CurrentMap_.getSymbol(xGG_m, yGG_m) == '`' || CurrentMap_.getSymbol(xGG_m, yGG_m) == '9' ||
           CurrentMap_.getSymbol(xGG_m, yGG_m) == 'x') &&
          GG_.status_ == 1) {
        if (GG_.confirmAsk_) {
          GG_.status_ = 2;
          GG_.mapX_ = xGG_m;
          GG_.mapY_ = yGG_m;
          GG_.confirmAsk_ = false;
          GG_.question_ = 0;
        } else {
          GG_.confirmAsk_ = true;
          GG_.question_ = 2;
        }

      } else {
        if ((CurrentMap_.getSymbol(xGG_m, yGG_m) == ' ' || CurrentMap_.getSymbol(xGG_m, yGG_m) == '.' ||
             CurrentMap_.getSymbol(xGG_m, yGG_m) == 'L') &&
            GG_.status_ == 2) {
          if (GG_.confirmAsk_) {
            GG_.status_ = 1;
            GG_.mapX_ = xGG_m;
            GG_.mapY_ = yGG_m;
            GG_.confirmAsk_ = false;
            GG_.question_ = 0;
          } else {
            GG_.confirmAsk_ = true;
            GG_.question_ = 3;
          }
        } else {
          if (CurrentMap_.getSymbol(xGG_m, yGG_m) == 'Z') {
            if (GG_.confirmAsk_) {
              CurrentMap_.choiseMap(1);
              locatePlayer(30, 20);
              GG_.confirmAsk_ = false;
              GG_.question_ = 0;
            } else {
              GG_.confirmAsk_ = true;
              GG_.question_ = 4;
            }
          }
        }
      }
    }
  }
  if (InputKey_.IsButtonQ()) {
    if (CurrentMap_.getSymbol(xGG_m, yGG_m) == 'v' || CurrentMap_.getSymbol(xGG_m, yGG_m) == '^' ||
        CurrentMap_.getSymbol(xGG_m, yGG_m) == '<' || CurrentMap_.getSymbol(xGG_m, yGG_m) == '>') {
      GG_.explanationAsk_ = true;
      GG_.explanation_ = 1;
    }
    if (CurrentMap_.getSymbol(xGG_m, yGG_m) == ';' || CurrentMap_.getSymbol(xGG_m, yGG_m) == '+' ||
        CurrentMap_.getSymbol(xGG_m, yGG_m) == '-' || CurrentMap_.getSymbol(xGG_m, yGG_m) == '?' ||
        CurrentMap_.getSymbol(xGG_m, yGG_m) == ':' || CurrentMap_.getSymbol(xGG_m, yGG_m) == 'J' ||
        CurrentMap_.getSymbol(xGG_m, yGG_m) == '`' || CurrentMap_.getSymbol(xGG_m, yGG_m) == '9' ||
        CurrentMap_.getSymbol(xGG_m, yGG_m) == 'x') {
      GG_.explanationAsk_ = true;
      GG_.explanation_ = 2;
    }
    if (CurrentMap_.getSymbol(xGG_m, yGG_m) == '#') {
      GG_.explanationAsk_ = true;
      GG_.explanation_ = 3;
    }
    if (CurrentMap_.getSymbol(xGG_m, yGG_m) == '_' || CurrentMap_.getSymbol(xGG_m, yGG_m) == ']' ||
        CurrentMap_.getSymbol(xGG_m, yGG_m) == '[') {
      GG_.explanationAsk_ = true;
      GG_.explanation_ = 4;
    }
    if (CurrentMap_.getSymbol(xGG_m, yGG_m) == 'L') {
      GG_.explanationAsk_ = true;
      GG_.explanation_ = 5;
    }
    if (CurrentMap_.getSymbol(xGG_m, yGG_m) == '"' || CurrentMap_.getSymbol(xGG_m, yGG_m) == '|' ||
        CurrentMap_.getSymbol(xGG_m, yGG_m) == '=') {
      GG_.explanationAsk_ = true;
      GG_.explanation_ = 6;
    }
    if (CurrentMap_.getSymbol(xGG_m, yGG_m) == 'W' || CurrentMap_.getSymbol(xGG_m, yGG_m) == 'w' ||
        CurrentMap_.getSymbol(xGG_m, yGG_m) == 'V') {
      GG_.explanationAsk_ = true;
      GG_.explanation_ = 7;
    }
    if (CurrentMap_.getSymbol(xGG_m, yGG_m) == 't') {
      GG_.explanationAsk_ = true;
      GG_.explanation_ = 8;
    }
    if (CurrentMap_.getSymbol(xGG_m, yGG_m) == '~') {
      GG_.explanationAsk_ = true;
      GG_.explanation_ = 9;
    }
  }
}

bool inGameLogic::movePlayer() {
  if (GG_.status_ == 1) {
    if (InputKey_.IsUp()) {
      GG_.course = 0;
      if (CurrentMap_.getSymbol(GG_.mapX_, GG_.mapY_ - 1) == ' ' || CurrentMap_.getSymbol(GG_.mapX_, GG_.mapY_ - 1) == '.' ||
          CurrentMap_.getSymbol(GG_.mapX_, GG_.mapY_ - 1) == 'L') {
        GG_.mapY_--;
        GG_.confirmAsk_ = false;
        GG_.question_ = 0;
        GG_.explanationAsk_ = false;
        GG_.explanation_ = 0;
        return true;
      }
    }
    if (InputKey_.IsDown()) {
      GG_.course = 3;

      if (CurrentMap_.getSymbol(GG_.mapX_, GG_.mapY_ + 1) == ' ' || CurrentMap_.getSymbol(GG_.mapX_, GG_.mapY_ + 1) == '.' ||
          CurrentMap_.getSymbol(GG_.mapX_, GG_.mapY_ + 1) == 'L' || CurrentMap_.getSymbol(GG_.mapX_, GG_.mapY_ + 1) == '_') {
        if (CurrentMap_.getSymbol(GG_.mapX_, GG_.mapY_) != '_') {
          GG_.mapY_++;
          GG_.confirmAsk_ = false;
          GG_.question_ = 0;
          GG_.explanationAsk_ = false;
          GG_.explanation_ = 0;
          return true;
        }
      }
    }
    if (InputKey_.IsLeft()) {
      GG_.course = 1;
      if (CurrentMap_.getSymbol(GG_.mapX_ - 1, GG_.mapY_) == ' ' || CurrentMap_.getSymbol(GG_.mapX_ - 1, GG_.mapY_) == '.' ||
          CurrentMap_.getSymbol(GG_.mapX_ - 1, GG_.mapY_) == 'L' || CurrentMap_.getSymbol(GG_.mapX_ - 1, GG_.mapY_) == '_') {
        GG_.mapX_--;
        GG_.confirmAsk_ = false;
        GG_.question_ = 0;
        GG_.explanationAsk_ = false;
        GG_.explanation_ = 0;
        return true;
      }
    }
    if (InputKey_.IsRight()) {
      GG_.course = 2;
      if (CurrentMap_.getSymbol(GG_.mapX_ + 1, GG_.mapY_) == ' ' || CurrentMap_.getSymbol(GG_.mapX_ + 1, GG_.mapY_) == '.' ||
          CurrentMap_.getSymbol(GG_.mapX_ + 1, GG_.mapY_) == 'L' || CurrentMap_.getSymbol(GG_.mapX_ + 1, GG_.mapY_) == '_') {
        GG_.mapX_++;
        GG_.confirmAsk_ = false;
        GG_.question_ = 0;
        GG_.explanationAsk_ = false;
        GG_.explanation_ = 0;
        return true;
      }
    }
  }
  if (GG_.status_ == 2) {
    if (InputKey_.IsUp()) {
      GG_.course = 0;
      if (CurrentMap_.getSymbol(GG_.mapX_, GG_.mapY_ - 1) == ';' || CurrentMap_.getSymbol(GG_.mapX_, GG_.mapY_ - 1) == '+' ||
          CurrentMap_.getSymbol(GG_.mapX_, GG_.mapY_ - 1) == '-' || CurrentMap_.getSymbol(GG_.mapX_, GG_.mapY_ - 1) == '?' ||
          CurrentMap_.getSymbol(GG_.mapX_, GG_.mapY_ - 1) == ':' || CurrentMap_.getSymbol(GG_.mapX_, GG_.mapY_ - 1) == 'J' ||
          CurrentMap_.getSymbol(GG_.mapX_, GG_.mapY_ - 1) == '`' || CurrentMap_.getSymbol(GG_.mapX_, GG_.mapY_ - 1) == '9' ||
          CurrentMap_.getSymbol(GG_.mapX_, GG_.mapY_ - 1) == 'x') {
        GG_.mapY_--;
        GG_.confirmAsk_ = false;
        GG_.question_ = 0;
        GG_.explanationAsk_ = false;
        GG_.explanation_ = 0;
        return true;
      }
    }
    if (InputKey_.IsDown()) {
      GG_.course = 3;

      if (CurrentMap_.getSymbol(GG_.mapX_, GG_.mapY_ + 1) == ';' || CurrentMap_.getSymbol(GG_.mapX_, GG_.mapY_ + 1) == '+' ||
          CurrentMap_.getSymbol(GG_.mapX_, GG_.mapY_ + 1) == '-' || CurrentMap_.getSymbol(GG_.mapX_, GG_.mapY_ + 1) == '?' ||
          CurrentMap_.getSymbol(GG_.mapX_, GG_.mapY_ + 1) == ':' || CurrentMap_.getSymbol(GG_.mapX_, GG_.mapY_ + 1) == 'J' ||
          CurrentMap_.getSymbol(GG_.mapX_, GG_.mapY_ + 1) == '`' || CurrentMap_.getSymbol(GG_.mapX_, GG_.mapY_ + 1) == '9' ||
          CurrentMap_.getSymbol(GG_.mapX_, GG_.mapY_ + 1) == 'x') {
        GG_.mapY_++;
        GG_.confirmAsk_ = false;
        GG_.question_ = 0;
        GG_.explanationAsk_ = false;
        GG_.explanation_ = 0;
        return true;
      }
    }
    if (InputKey_.IsLeft()) {
      GG_.course = 1;
      if (CurrentMap_.getSymbol(GG_.mapX_ - 1, GG_.mapY_) == ';' || CurrentMap_.getSymbol(GG_.mapX_ - 1, GG_.mapY_) == '+' ||
          CurrentMap_.getSymbol(GG_.mapX_ - 1, GG_.mapY_) == '-' || CurrentMap_.getSymbol(GG_.mapX_ - 1, GG_.mapY_) == '?' ||
          CurrentMap_.getSymbol(GG_.mapX_ - 1, GG_.mapY_) == ':' || CurrentMap_.getSymbol(GG_.mapX_ - 1, GG_.mapY_) == 'J' ||
          CurrentMap_.getSymbol(GG_.mapX_ - 1, GG_.mapY_) == '`' || CurrentMap_.getSymbol(GG_.mapX_ - 1, GG_.mapY_) == '9' ||
          CurrentMap_.getSymbol(GG_.mapX_ - 1, GG_.mapY_) == 'x') {
        GG_.mapX_--;
        GG_.confirmAsk_ = false;
        GG_.question_ = 0;
        GG_.explanationAsk_ = false;
        GG_.explanation_ = 0;
        return true;
      }
    }
    if (InputKey_.IsRight()) {
      GG_.course = 2;
      if (CurrentMap_.getSymbol(GG_.mapX_ + 1, GG_.mapY_) == ';' || CurrentMap_.getSymbol(GG_.mapX_ + 1, GG_.mapY_) == '+' ||
          CurrentMap_.getSymbol(GG_.mapX_ + 1, GG_.mapY_) == '-' || CurrentMap_.getSymbol(GG_.mapX_ + 1, GG_.mapY_) == '?' ||
          CurrentMap_.getSymbol(GG_.mapX_ + 1, GG_.mapY_) == ':' || CurrentMap_.getSymbol(GG_.mapX_ + 1, GG_.mapY_) == 'J' ||
          CurrentMap_.getSymbol(GG_.mapX_ + 1, GG_.mapY_) == '`' || CurrentMap_.getSymbol(GG_.mapX_ + 1, GG_.mapY_) == '9' ||
          CurrentMap_.getSymbol(GG_.mapX_ + 1, GG_.mapY_) == 'x') {
        GG_.mapX_++;
        GG_.confirmAsk_ = false;
        GG_.question_ = 0;
        GG_.explanationAsk_ = false;
        GG_.explanation_ = 0;
        return true;
      }
    }
  }
  return false;
}

void inGameLogic::Update() {
  movePlayer();
  actionPlayer();
}

inGameLogic::inGameLogic(inputKey &InputKey, bool NewGame) : InputKey_(InputKey) {
  if (NewGame) {
    CurrentMap_.choiseMap(0);
  }
}

void inGameLogic::createPlayer(unsigned x, unsigned y) {
  GG_.pullTerrain(x, y);
  GG_.status_ = 1;
  Render.createPlayerScreen(GG_.playerName_, GG_.playerNation_);
  switch (GG_.playerNation_) {
    case 1: {
      GG_.attack_ = 50;
      GG_.block_ = 0.35;
      GG_.HP_ = 100;
      GG_.MP_ = 70;
      GG_.AP_ = 110;
      GG_.SP_ = 2;
      break;
    }
    case 2: {
      GG_.attack_ = 30;
      GG_.block_ = 0.15;
      GG_.HP_ = 90;
      GG_.MP_ = 120;
      GG_.AP_ = 100;
      GG_.SP_ = 1;
      break;
    }
    case 3: {
      GG_.attack_ = 45;
      GG_.block_ = 0.3;
      GG_.HP_ = 90;
      GG_.MP_ = 60;
      GG_.AP_ = 140;
      GG_.SP_ = 1;
      break;
    }
    case 4: {
      GG_.attack_ = 40;
      GG_.block_ = 0.2;
      GG_.HP_ = 100;
      GG_.MP_ = 100;
      GG_.AP_ = 100;
      GG_.SP_ = 1;
      break;
    }
    case 5: {
      GG_.attack_ = 25;
      GG_.block_ = 0.1;
      GG_.HP_ = 80;
      GG_.MP_ = 150;
      GG_.AP_ = 60;
      GG_.SP_ = 2;
      break;
    }
    case 6: {
      GG_.attack_ = 30;
      GG_.block_ = 0.15;
      GG_.HP_ = 100;
      GG_.MP_ = 130;
      GG_.AP_ = 70;
      GG_.SP_ = 1;
      break;
    }
    case 7: {
      GG_.attack_ = 40;
      GG_.block_ = 0.2;
      GG_.HP_ = 90;
      GG_.MP_ = 110;
      GG_.AP_ = 150;
      GG_.SP_ = 1;
      break;
    }
    case 8: {
      GG_.attack_ = 50;
      GG_.block_ = 0.3;
      GG_.HP_ = 110;
      GG_.MP_ = 80;
      GG_.AP_ = 110;
      GG_.SP_ = 1;
      break;
    }
    case 9: {
      GG_.attack_ = 35;
      GG_.block_ = 0.2;
      GG_.HP_ = 80;
      GG_.MP_ = 70;
      GG_.AP_ = 90;
      GG_.SP_ = 4;
      break;
    }
    case 10: {
      GG_.attack_ = 65;
      GG_.block_ = 0.05;
      GG_.HP_ = 80;
      GG_.MP_ = 80;
      GG_.AP_ = 150;
      GG_.SP_ = 4;
      break;
    }
    default: {
      GG_.attack_ = 0;
      GG_.block_ = 0;
      GG_.HP_ = 0;
      GG_.MP_ = 0;
      GG_.AP_ = 0;
      GG_.SP_ = 0;
      break;
    }
  }
}

void inGameLogic::locatePlayer(unsigned x, unsigned y) {
  GG_.pullTerrain(x, y);
  GG_.status_ = 1;
}

void inGameLogic::play() {
  double lag = .0;
  double lastTime = clock();
  lastTime = lastTime / CLOCKS_PER_SEC;
  do {
    double currentTime = clock();
    currentTime = currentTime / CLOCKS_PER_SEC;
    double eslapsedTime = currentTime - lastTime;
    lastTime = currentTime;
    lag += eslapsedTime;

    InputKey_.Update();
    // while (lag >= FRAMES_PER_SECOND_) {
    Update();
    // lag -= FRAMES_PER_SECOND_;
    // }

    Render.clearALL();
    Render.goRender(CurrentMap_, GG_);

    if (InputKey_.IsExit()) {
      break;
    }
  } while (true);
}

// int inGameLogic::action(){}
/*void inGameLogic::update() {}
void inGameLogic::actionPlayer(hud &HUD, map &map, player &GG, int &xGG, int &yGG) {
  int xGG_m, yGG_m;  // Дополнительные маркеры
  if (GG.course == 0) {
    xGG_m = xGG;
    yGG_m = yGG - 1;
  }
  if (GG.course == 3) {
    xGG_m = xGG;
    yGG_m = yGG + 1;
  }
  if (GG.course == 1) {
    yGG_m = yGG;
    xGG_m = xGG - 1;
  }
  if (GG.course == 2) {
    yGG_m = yGG;
    xGG_m = xGG + 1;
  }
  if (InputKey_.IsButtonE()) {
    if (HUD.askDoorMark) {
      xGG = xGG_m;
      yGG = yGG_m;
      HUD.dialog = false;
      HUD.askDoorMark = false;

    } else {
      if (map.getSymbol(xGG_m, yGG_m) == 'v' || map.getSymbol(xGG_m, yGG_m) == '^' ||
          map.getSymbol(xGG_m, yGG_m) == '<' || map.getSymbol(xGG_m, yGG_m) == '>') {
        HUD.askDoorMark = HUD.askDoor();
      } else {
        if (HUD.askArmorMark) {
          HUD.dialog = false;
          HUD.askArmorMark = false;
        } else {
          if (map.getSymbol(xGG_m, yGG_m) == 'A') {
            HUD.askArmorMark = HUD.askArmor();
          }
        }
      }
    }
  }
}

bool inGameLogic::movePlayer(player &GG, map &map, int &xGG, int &yGG) {
  if (InputKey_.IsUp()) {
    GG.course = 0;
    if (map.getSymbol(xGG, yGG - 1) == ' ' || map.getSymbol(xGG, yGG - 1) == '.') {
      yGG--;
      return true;
    }
  }
  if (InputKey_.IsDown()) {
    GG.course = 3;
    if (map.getSymbol(xGG, yGG + 1) == ' ' || map.getSymbol(xGG, yGG + 1) == '.') {
      yGG++;
      return true;
    }
  }
  if (InputKey_.IsLeft()) {
    GG.course = 1;
    if (map.getSymbol(xGG - 1, yGG) == ' ' || map.getSymbol(xGG - 1, yGG) == '.') {
      xGG--;
      return true;
    }
  }
  if (InputKey_.IsRight()) {
    GG.course = 2;
    if (map.getSymbol(xGG + 1, yGG) == ' ' || map.getSymbol(xGG + 1, yGG) == '.') {
      xGG++;
      return true;
    }
  }
  return false;
}
void inGameLogic::inGameFT() {  //первый запуск
  int xGG = 37, yGG = 25, schet = 0;
  map startMap(0);
  startMap.getSize(mapX, mapY);
  player GG(xGG, yGG);
  hud HUD(GG);
  while (true) {
    InputKey_.Update();
    if (movePlayer(GG, startMap, xGG, yGG)) {
      schet++;
    }
    actionPlayer(HUD, startMap, GG, xGG, yGG);

    if (InputKey_.IsExit()) {
      break;
    }
    GG.putTerrain(xGG, yGG);

    GG_.goRender(startMap, GG, HUD);
    terminal_print(65, 30, "Шагов: ");
    terminal_refresh();
  }
}*/
