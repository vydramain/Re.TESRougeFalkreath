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

  for (int i(0); i < yGG_m; i++) {
    xGG_m++;
  }
  /*
  if (InputKey_.IsButtonE()) {
    if (HUD.askDoorMark) {
      xGG = xGG_m;
      yGG = yGG_m;
      HUD.dialog = false;
      HUD.askDoorMark = false;

    } else {
      if (map.getSymbol(xGG_m, yGG_m) == 'v' || map.getSymbol(xGG_m, yGG_m) == '^' || map.getSymbol(xGG_m, yGG_m) == '<' ||
          map.getSymbol(xGG_m, yGG_m) == '>') {
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
  }*/
}

bool inGameLogic::movePlayer() {
  if (InputKey_.IsUp()) {
    GG_.course = 0;
    if (CurrentMap_.getSymbol(GG_.mapX_, GG_.mapY_ - 1) == ' ' || CurrentMap_.getSymbol(GG_.mapX_, GG_.mapY_ - 1) == '.') {
      GG_.mapY_--;
      return true;
    }
  }
  if (InputKey_.IsDown()) {
    GG_.course = 3;
    if (CurrentMap_.getSymbol(GG_.mapX_, GG_.mapY_ + 1) == ' ' || CurrentMap_.getSymbol(GG_.mapX_, GG_.mapY_ + 1) == '.') {
      GG_.mapY_++;
      return true;
    }
  }
  if (InputKey_.IsLeft()) {
    GG_.course = 1;
    if (CurrentMap_.getSymbol(GG_.mapX_ - 1, GG_.mapY_) == ' ' || CurrentMap_.getSymbol(GG_.mapX_ - 1, GG_.mapY_) == '.') {
      GG_.mapX_--;
      return true;
    }
  }
  if (InputKey_.IsRight()) {
    GG_.course = 2;
    if (CurrentMap_.getSymbol(GG_.mapX_ + 1, GG_.mapY_) == ' ' || CurrentMap_.getSymbol(GG_.mapX_ + 1, GG_.mapY_) == '.') {
      GG_.mapX_++;
      return true;
    }
  }
  return false;
}

void inGameLogic::Update() {
  movePlayer();
}

inGameLogic::inGameLogic(inputKey &InputKey, bool NewGame) : InputKey_(InputKey) {
  if (NewGame) {
    CurrentMap_.choiseMap(0);
  }
}

void inGameLogic::createPlayer(renderGame &Render) {
  Render.inputQuestion("Введите имя игрока: ", 20, GG_.playerName_);
  const char *listMenu[10] = {"Норд",        "Бретон",      "Радгард", "Имперец",    "Высокий Эльф",
                              "Тёмный эльф", "Лесной эльф", "Орк",     "Аргонианин", "Каджит"};
  GG_.playerNation_ = Render.inputChoose(listMenu, 10, "Раса: ", 6);
  GG_.pullTerrain(30, 20);
}

void inGameLogic::play(renderGame &Render) {
  do {
    InputKey_.Update();
    Update();
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

    render.goRender(startMap, GG, HUD);
    terminal_print(65, 30, "Шагов: ");
    terminal_refresh();
  }
}*/
