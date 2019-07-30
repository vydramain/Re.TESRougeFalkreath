//
// Created by vydra on 7/23/19.
//

#include "../Headers/inGameLogic.h"

inGameLogic::inGameLogic(const inputKey &InputKey, bool NewGame) : InputKey_(InputKey) {
  if (NewGame) {
    World currentLocation(0);
    createPlayer();
  }
}

void inGameLogic::createPlayer() {
  char  *GGName = nullptr;
  unsigned nation;
  render.inputQuestion("Введите имя игрока: ", GGName);
  GG_.pullName(GGName);
  const char *listMenu[10] = {"Норд",        "Бретон",      "Радгард", "Имперец",    "Высокий Эльф",
                              "Тёмный эльф", "Лесной эльф", "Орк",     "Аргонианин", "Каджит"};
  nation = render.inputChoose(listMenu, 10, "Раса: ");
  GG_.pullNation(nation);
  GG_.pullTerrain(30, 20);
}

// int inGameLogic::action(){}
/*void inGameLogic::update() {}
void inGameLogic::actionPlayer(hud &HUD, Map &map, player &GG, int &xGG, int &yGG) {
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

bool inGameLogic::movePlayer(player &GG, Map &map, int &xGG, int &yGG) {
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
  Map startMap(0);
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
