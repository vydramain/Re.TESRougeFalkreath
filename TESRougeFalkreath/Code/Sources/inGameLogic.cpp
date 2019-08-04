//
// Created by vydra on 7/23/19.
//

#include "../Headers/inGameLogic.h"
void inGameLogic::actionPlayer(renderGame &Render) {
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
      if (Render.confirmAsk_) {
        GG_.mapX_ = xGG_m;
        GG_.mapY_ = yGG_m;
        Render.confirmAsk_ = false;
        Render.question_ = 0;
      } else {
        Render.confirmAsk_ = true;
        Render.question_ = 1;
      }
    } else {
      if (CurrentMap_.getSymbol(xGG_m, yGG_m) == ';' || CurrentMap_.getSymbol(xGG_m, yGG_m) == '+' ||
          CurrentMap_.getSymbol(xGG_m, yGG_m) == '-' || CurrentMap_.getSymbol(xGG_m, yGG_m) == '?' ||
          CurrentMap_.getSymbol(xGG_m, yGG_m) == ':' || CurrentMap_.getSymbol(xGG_m, yGG_m) == 'J' ||
          CurrentMap_.getSymbol(xGG_m, yGG_m) == '`') {
        if (Render.confirmAsk_) {
          GG_.mapX_ = xGG_m;
          GG_.mapY_ = yGG_m;
          Render.confirmAsk_ = false;
          Render.question_ = 0;
        } else {
          Render.confirmAsk_ = true;
          Render.question_ = 2;
        }
      } else {
        if (CurrentMap_.getSymbol(xGG_m, yGG_m) == 'A' || CurrentMap_.getSymbol(xGG_m, yGG_m) == 'Y' ||
            CurrentMap_.getSymbol(xGG_m, yGG_m) == 'T') {
          if (GG_.status_ != 0) {
            Render.confirmAsk_ = true;
            Render.question_ = 11;
          } else {
            if (Render.confirmAsk_) {
              if (CurrentMap_.getSymbol(xGG_m, yGG_m) == 'A') {
                GG_.status_ = 1;
                CurrentMap_.changeSymbol(xGG_m, yGG_m);
              }
              if (CurrentMap_.getSymbol(xGG_m, yGG_m) == 'Y') {
                GG_.status_ = 2;
                CurrentMap_.changeSymbol(xGG_m, yGG_m);
              }
              if (CurrentMap_.getSymbol(xGG_m, yGG_m) == 'T') {
                GG_.status_ = 3;
                CurrentMap_.changeSymbol(xGG_m, yGG_m);
              }
              GG_.mapX_ = xGG_m;
              GG_.mapY_ = yGG_m;
              Render.confirmAsk_ = false;
              Render.question_ = 0;
            } else {
              Render.confirmAsk_ = true;
              Render.question_ = 10;
            }
          }
        }
      }
    }
  } else {
    if (InputKey_.IsButtonQ()) {
      if (CurrentMap_.getSymbol(xGG_m, yGG_m) == 'v' || CurrentMap_.getSymbol(xGG_m, yGG_m) == '^' ||
          CurrentMap_.getSymbol(xGG_m, yGG_m) == '<' || CurrentMap_.getSymbol(xGG_m, yGG_m) == '>') {
        Render.explanationAsk_ = true;
        Render.explanation_ = 1;
      }
      if (CurrentMap_.getSymbol(xGG_m, yGG_m) == ';' || CurrentMap_.getSymbol(xGG_m, yGG_m) == '+' ||
          CurrentMap_.getSymbol(xGG_m, yGG_m) == '-' || CurrentMap_.getSymbol(xGG_m, yGG_m) == '?' ||
          CurrentMap_.getSymbol(xGG_m, yGG_m) == ':' || CurrentMap_.getSymbol(xGG_m, yGG_m) == 'J' ||
          CurrentMap_.getSymbol(xGG_m, yGG_m) == '`') {
        Render.explanationAsk_ = true;
        Render.explanation_ = 2;
      }
      if (CurrentMap_.getSymbol(xGG_m, yGG_m) == '#') {
        Render.explanationAsk_ = true;
        Render.explanation_ = 3;
      }
      if (CurrentMap_.getSymbol(xGG_m, yGG_m) == '_' || CurrentMap_.getSymbol(xGG_m, yGG_m) == ']') {
        Render.explanationAsk_ = true;
        Render.explanation_ = 4;
      }
      if (CurrentMap_.getSymbol(xGG_m, yGG_m) == 'L') {
        Render.explanationAsk_ = true;
        Render.explanation_ = 5;
      }
      if (CurrentMap_.getSymbol(xGG_m, yGG_m) == '"' || CurrentMap_.getSymbol(xGG_m, yGG_m) == '|' ||
          CurrentMap_.getSymbol(xGG_m, yGG_m) == '=') {
        Render.explanationAsk_ = true;
        Render.explanation_ = 6;
      }
      if (CurrentMap_.getSymbol(xGG_m, yGG_m) == 'W' || CurrentMap_.getSymbol(xGG_m, yGG_m) == 'w' ||
          CurrentMap_.getSymbol(xGG_m, yGG_m) == 'V') {
        Render.explanationAsk_ = true;
        Render.explanation_ = 7;
      }
      if (CurrentMap_.getSymbol(xGG_m, yGG_m) == 't') {
        Render.explanationAsk_ = true;
        Render.explanation_ = 8;
      }
      if (CurrentMap_.getSymbol(xGG_m, yGG_m) == '~') {
        Render.explanationAsk_ = true;
        Render.explanation_ = 9;
      }
    }
  }
}

bool inGameLogic::movePlayer(renderGame &Render) {
  if (InputKey_.IsUp()) {
    GG_.course = 0;
    if (CurrentMap_.getSymbol(GG_.mapX_, GG_.mapY_ - 1) == ' ' || CurrentMap_.getSymbol(GG_.mapX_, GG_.mapY_ - 1) == '.' ||
        CurrentMap_.getSymbol(GG_.mapX_, GG_.mapY_ - 1) == 'L') {
      GG_.mapY_--;
      Render.confirmAsk_ = false;
      Render.question_ = 0;
      Render.explanationAsk_ = false;
      Render.explanation_ = 0;
      return true;
    }
  }
  if (InputKey_.IsDown()) {
    GG_.course = 3;

    if (CurrentMap_.getSymbol(GG_.mapX_, GG_.mapY_ + 1) == ' ' || CurrentMap_.getSymbol(GG_.mapX_, GG_.mapY_ + 1) == '.' ||
        CurrentMap_.getSymbol(GG_.mapX_, GG_.mapY_ + 1) == 'L' || CurrentMap_.getSymbol(GG_.mapX_, GG_.mapY_ + 1) == '_') {
      if (CurrentMap_.getSymbol(GG_.mapX_, GG_.mapY_) != '_') {
        GG_.mapY_++;
        Render.confirmAsk_ = false;
        Render.question_ = 0;
        Render.explanationAsk_ = false;
        Render.explanation_ = 0;
        return true;
      }
    }
  }
  if (InputKey_.IsLeft()) {
    GG_.course = 1;
    if (CurrentMap_.getSymbol(GG_.mapX_ - 1, GG_.mapY_) == ' ' || CurrentMap_.getSymbol(GG_.mapX_ - 1, GG_.mapY_) == '.' ||
        CurrentMap_.getSymbol(GG_.mapX_ - 1, GG_.mapY_) == 'L' || CurrentMap_.getSymbol(GG_.mapX_ - 1, GG_.mapY_) == '_') {
      GG_.mapX_--;
      Render.confirmAsk_ = false;
      Render.question_ = 0;
      Render.explanationAsk_ = false;
      Render.explanation_ = 0;
      return true;
    }
  }
  if (InputKey_.IsRight()) {
    GG_.course = 2;
    if (CurrentMap_.getSymbol(GG_.mapX_ + 1, GG_.mapY_) == ' ' || CurrentMap_.getSymbol(GG_.mapX_ + 1, GG_.mapY_) == '.' ||
        CurrentMap_.getSymbol(GG_.mapX_ + 1, GG_.mapY_) == 'L' || CurrentMap_.getSymbol(GG_.mapX_ + 1, GG_.mapY_) == '_') {
      GG_.mapX_++;
      Render.confirmAsk_ = false;
      Render.question_ = 0;
      Render.explanationAsk_ = false;
      Render.explanation_ = 0;
      return true;
    }
  }
  return false;
}

void inGameLogic::Update(renderGame &Render) {
  movePlayer(Render);
  actionPlayer(Render);
}

inGameLogic::inGameLogic(inputKey &InputKey, bool NewGame) : InputKey_(InputKey) {
  if (NewGame) {
    CurrentMap_.choiseMap(0);
  }
}

void inGameLogic::createPlayer(renderGame &Render) {
  GG_.pullTerrain(30, 20);
  Render.inputQuestion("Введите имя игрока: ", 20, GG_.playerName_);
  const char *listMenu[10] = {"Норд",        "Бретонец",    "Редгард", "Имперец",    "Высокий Эльф",
                              "Тёмный эльф", "Лесной эльф", "Орк",     "Аргонианин", "Каджит"};
  GG_.playerNation_ = Render.inputChoose(listMenu, 10, "Раса: ", 6);
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

void inGameLogic::play(renderGame &Render) {
  do {
    InputKey_.Update();
    Update(Render);
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
