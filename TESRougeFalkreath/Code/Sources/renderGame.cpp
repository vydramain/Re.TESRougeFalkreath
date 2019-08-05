//
// Created by vydra on 7/23/19.
//

#include "../Headers/renderGame.h"

renderGame::renderGame() {
  terminal_open();
  terminal_set("window: title='TES Falkreath', cellsize=8x15, size=100x40, fullscreen=true; font: ./Fonts/Ubuntu-C.ttf, size=12");
  terminal_refresh();
}

renderGame::renderGame(bool gameMode) {
  if (gameMode) {
    terminal_open();
    terminal_set("window: title='TES Falkreath', cellsize=8x15, size=100x40, fullscreen=true; font: ./Fonts/Ubuntu-C.ttf, size=12");
    terminal_refresh();
  } else {
    terminal_open();
    terminal_set("window: title='TES Falkreath', size=20x26; font: ./Fonts/Ubuntu-C.ttf, size=11");
    terminal_refresh();
  }
}

renderGame::~renderGame() {
  terminal_close();
}

/*
void renderGame::WOW() {
  terminal_layer(15);
  terminal_print(1, 0, "WOW!!");
  terminal_refresh();
}

void renderGame::clearWOW() {
  terminal_layer(15);
  terminal_clear_area(1, 0, 6, 0);
  terminal_refresh();
}
*/

void renderGame::createPlayerScreen(char *NameOfGG, unsigned &Race) {
  inputQuestion("Введите имя игрока: ", 20, NameOfGG);
  const char *listMenu[10] = {"Норд",        "Бретонец",    "Редгард", "Имперец",    "Высокий Эльф",
                              "Тёмный эльф", "Лесной эльф", "Орк",     "Аргонианин", "Каджит"};
  Race = inputChoose(listMenu, 10, "Раса: ", 6);
  terminal_clear();
}

void renderGame::clearALL() {
  for (unsigned i(0); i < 20; i++) {
    terminal_layer(i);
    terminal_clear();
  }
}

void renderGame::goRender(const map &currentMap, const player &GG) {
  showMap(currentMap, GG.mapX_, GG.mapY_);
  showPlayer(GG);
  showHud(currentMap, GG);
  terminal_refresh();
}

bool renderGame::menuChoiser(unsigned &nonshoise, unsigned pointMuch) {  // НЕ КОНСТАНТА
  inputKey InputKey;
  InputKey.Update();
  if (InputKey.IsUp() && nonshoise > 1) {
    nonshoise--;
  } else {
    if (InputKey.IsDown() && nonshoise < pointMuch) {
      nonshoise++;
    }
  }
  if (InputKey.IsExit()) {
    nonshoise = 0;
    return true;
  } else {
    if (InputKey.IsEnter() && nonshoise != 0) {
      return true;
    } else {
      return false;
    }
  }
}

unsigned renderGame::headMenu() {
  bool IsGo(false);
  unsigned nonchoise(0);  // Процесс выбора:
                          // 1 - Новая игра
                          // 2 - Выход
  while (IsGo == false) {
    terminal_clear();
    IsGo = menuChoiser(nonchoise, 5);
    switch (nonchoise) {
      case 1: {
        terminal_print(1, 8, "--> Новая Игра <--");
        terminal_print(4, 9, "  Загрузка  ");
        terminal_print(4, 10, " Сохранения ");
        terminal_print(4, 11, "Конфигурация");
        terminal_print(4, 12, " Конец Игры ");
        break;
      }
      case 2: {
        terminal_print(4, 8, " Новая Игра ");
        terminal_print(0, 9, "--> (неработает) <--");
        terminal_print(4, 10, " Сохранения ");
        terminal_print(4, 11, "Конфигурация");
        terminal_print(4, 12, " Конец Игры ");
        break;
      }
      case 3: {
        terminal_print(4, 8, " Новая Игра ");
        terminal_print(4, 9, "  Загрузка  ");
        terminal_print(0, 10, "--> (неработает) <--");
        terminal_print(4, 11, "Конфигурация");
        terminal_print(4, 12, " Конец Игры ");
        break;
      }
      case 4: {
        terminal_print(4, 8, " Новая Игра ");
        terminal_print(4, 9, "  Загрузка  ");
        terminal_print(4, 10, " Сохранения ");
        terminal_print(0, 11, "--> (неработает) <--");
        terminal_print(4, 12, " Конец Игры ");
        break;
      }
      case 5: {
        terminal_print(4, 8, " Новая Игра ");
        terminal_print(4, 9, "  Загрузка  ");
        terminal_print(4, 10, " Сохранения ");
        terminal_print(4, 11, "Конфигурация");
        terminal_print(1, 12, "--> Конец Игры <--");
        break;
      }
      default: {
        terminal_print(4, 8, " Новая Игра ");
        terminal_print(4, 9, "  Загрузка  ");
        terminal_print(4, 10, " Сохранения ");
        terminal_print(4, 11, "Конфигурация");
        terminal_print(4, 12, " Конец Игры ");
        break;
      }
    }

    terminal_refresh();
  }
  return nonchoise;
}

bool renderGame::inputQuestion(const char *zagolovok, unsigned zagolovokSize, char *GGName) {
  terminal_clear();
  terminal_print(1, 1, zagolovok);
  terminal_refresh();
  terminal_read_str(1 + zagolovokSize, 1, GGName, 12);
  return true;
}

unsigned renderGame::inputChoose(const char **listMenu, const unsigned &menuPoint, const char *zagolovok, unsigned zagolovokSize) {
  bool IsGo(false);
  unsigned choise(0);
  do {
    terminal_clear();
    terminal_print(1, 1, zagolovok);
    for (unsigned i = 0; i < menuPoint; i++) {
      terminal_print(1 + zagolovokSize + 5, 1 + i, listMenu[i]);
      if (i == choise - 1) {
        terminal_print(1 + zagolovokSize, 1 + i, "--> ");
      }
    }
    terminal_refresh();
    IsGo = menuChoiser(choise, 10);
  } while (IsGo == false);
  return choise;
}

void renderGame::symColor(char mapSym) {
  switch (mapSym) {
    case '~': {
      terminal_color(0xcc00ffff);
      break;
    }
    case ';':
    case '+':
    case '-':
    case '?':
    case ':':
    case 'J':
    case '`':
    case 'x':
    case '9': {
      terminal_color(0xff26cf26);
      break;
    }
    case '[':
    case ']':
    case '_': {
      terminal_color(0xff7f7f7f);
      break;
    }
    case 'W':
    case 'w':
    case 'V': {
      terminal_color(0xffe3c347);
      break;
    }
    case '"':
    case '|':
    case '=':
    case '>':
    case '^':
    case 'v':
    case '<': {
      terminal_color(0xffba7300);
      break;
    }
    case '#': {
      terminal_color(0xff666666);
      break;
    }
    case 'L': {
      terminal_color(0xffabff00);
      break;
    }
    case 't': {
      terminal_color(0xffb2b2b2);
      break;
    }
    case 'Z': {
      terminal_color(0xffffff00);
      break;
    }
    default: {
      terminal_color(0xff4c4c4c);
      break;
    }
  }
}

void renderGame::showMap(const map &currentLocation, int xPlayer, int yPlayer) {
  terminal_layer(10);
  for (int ii(0); ii < mapBorderY; ii++) {
    for (int i(0); i < mapBorderX; i++) {
      terminal_color(0xaaffffff);
      if (yPlayer - 20 + ii <= 0) {
        terminal_put(i, ii, ' ');
      } else {
        if (xPlayer - 30 + i <= 0) {
          terminal_put(i, ii, ' ');
        } else {
          if (yPlayer - 20 + ii >= currentLocation.mapYSize_) {
            terminal_put(i, ii, ' ');
          } else {
            if (xPlayer - 30 + i >= currentLocation.mapXSize_) {
              terminal_put(i, ii, ' ');
            } else {
              symColor(currentLocation.mapChar_[yPlayer - 20 + ii][xPlayer - 30 + i]);
              terminal_put(i, ii, currentLocation.mapChar_[yPlayer - 20 + ii][xPlayer - 30 + i]);
            }
          }
        }
      }
    }
  }
}

void renderGame::showPlayer(const player &GG) {
  terminal_layer(1);
  terminal_color(0xffffffff);
  if (GG.status_ == 2) {
    terminal_color(0xff00ff00);
  }
  terminal_put_ext(GG.screenX_, GG.screenY_, 0, -1, GG.naked);
  terminal_color(0xffffffff);
}

void renderGame::showHud(const map &CurrentMap, const player &GG) {
  terminal_layer(10);
  for (int i(0); i < screenBorderY; i++) {
    terminal_print(mapBorderX, i, "|");
  }
  terminal_print(mapBorderX + 1, 1, "Имя:");
  terminal_print(mapBorderX + 1, 2, "Расса:");
  terminal_print(mapBorderX + 1, 3, "Статус:");
  terminal_print(mapBorderX + 1, 4, "ОЗ:");
  terminal_print(mapBorderX + 1, 5, "OМ:");
  terminal_print(mapBorderX + 1, 6, "ОД:");
  terminal_print(mapBorderX + 1, 7, "ОС:");

  terminal_print(mapBorderX + 1, mapBorderY - 3, "Управление - Стрелки");
  terminal_print(mapBorderX + 1, mapBorderY - 2, "Использовать - E");
  terminal_print(mapBorderX + 1, mapBorderY - 1, "Осмотреть - Q");  // Временно

  switch (GG.playerNation_) {
    case 1: {
      strcpy(nationality, "Норд");
      break;
    }
    case 2: {
      strcpy(nationality, "Бретонец");
      break;
    }
    case 3: {
      strcpy(nationality, "Редгард");
      break;
    }
    case 4: {
      strcpy(nationality, "Имперец");
      break;
    }
    case 5: {
      strcpy(nationality, "Высокий Эльф");
      break;
    }
    case 6: {
      strcpy(nationality, "Тёмный Эльф");
      break;
    }
    case 7: {
      strcpy(nationality, "Лесной Эльф");
      break;
    }
    case 8: {
      strcpy(nationality, "Орк");
      break;
    }
    case 9: {
      strcpy(nationality, "Аргонианин");
      break;
    }
    case 10: {
      strcpy(nationality, "Каджит");
      break;
    }
    default: {
      strcpy(nationality, " ");
      break;
    }
  }

  terminal_print(mapBorderX + 1 + 5, 1, GG.playerName_);
  terminal_print(mapBorderX + 1 + 7, 2, nationality);
  terminal_print(mapBorderX + 1 + 8, 3, "Неизвестный");

  char hp[5], mp[5], ap[5], sp[3];
  sprintf(hp, "%d", GG.HP_);
  sprintf(mp, "%d", GG.MP_);
  sprintf(ap, "%d", GG.AP_);
  sprintf(sp, "%d", GG.SP_);
  terminal_print(mapBorderX + 1 + 5, 4, hp);
  terminal_print(mapBorderX + 1 + 5, 5, mp);
  terminal_print(mapBorderX + 1 + 5, 6, ap);
  terminal_print(mapBorderX + 1 + 5, 7, sp);

  terminal_print(mapBorderX + 1, 9, "________________________________");
  terminal_print(mapBorderX + 1, mapBorderY - 5, "________________________________");

  terminal_print(mapBorderX + 1, 11, "Инвентарь:");
  terminal_print(mapBorderX + 1, 12, "---");
  terminal_print(mapBorderX + 1, 13, "---");
  terminal_print(mapBorderX + 1, 14, "---");
  terminal_print(mapBorderX + 1, 15, "---");
  terminal_print(mapBorderX + 1, 16, "---");
  terminal_print(mapBorderX + 1, 17, "---");
  terminal_print(mapBorderX + 1, 18, "---");

  if (GG.confirmAsk_ || GG.explanationAsk_) {
    showDialog(CurrentMap, GG);
  }
}

void renderGame::showDialog(const map &CurrentMap, const player &GG) {
  terminal_clear_area(0, mapBorderY - 10, mapBorderX, mapBorderY);
  for (int i(0); i < mapBorderX; i++) {
    terminal_put(i, mapBorderY - 10, '_');
  }
  if (GG.question_ != 0) {
    if (GG.question_ == 1) {
      terminal_print(1, mapBorderY - 7, "Открыть дверь?");
    } else {
      if (GG.question_ == 2) {
        terminal_print(1, mapBorderY - 7, "Спрятаться в зелени?");
      } else {
        if (GG.question_ == 3) {
          terminal_print(1, mapBorderY - 7, "Перестать прятаться?");
        } else {
          if (GG.question_ == 4) {
            if (CurrentMap.mapName_ == 0) {
              terminal_print(1, mapBorderY - 7, "Отправиться в Восточный Лес?");
            }
          } else {
            if (GG.question_ == 10) {
              terminal_print(1, mapBorderY - 7, "Надеть броню?");
            } else {
              if (GG.question_ == 11) {
                terminal_print(1, mapBorderY - 7, "У тебя уже есть броня! (жадина)");
              }
            }
          }
        }
      }
    }
  } else {
    if (GG.explanation_ != 0) {
      if (GG.explanation_ == 1) {
        terminal_print(1, mapBorderY - 7, "Это дверь.");
        terminal_print(1, mapBorderY - 6, "Похоже, изготовлена из многовековой ели.");
      }
      if (GG.explanation_ == 2) {
        terminal_print(1, mapBorderY - 7, "Это хвойное растение.");
        terminal_print(1, mapBorderY - 6, "Похоже на ель.");
      }
      if (GG.explanation_ == 3) {
        terminal_print(1, mapBorderY - 7, "Камень.");
        terminal_print(1, mapBorderY - 6, "Мне через него не перебраться.");
      }
      if (GG.explanation_ == 4) {
        terminal_print(1, mapBorderY - 7, "Гладкая каменная стена....");
        terminal_print(1, mapBorderY - 6, "          ...из хорошего булыжника.");
      }
      if (GG.explanation_ == 5) {
        terminal_print(1, mapBorderY - 7, "Пшеница... ");
        terminal_print(1, mapBorderY - 6, "Несозревшая...");
      }
      if (GG.explanation_ == 6) {
        terminal_print(1, mapBorderY - 7, "Ствол... ");
        terminal_print(1, mapBorderY - 6, "Просто ствол дерева...");
      }
      if (GG.explanation_ == 7) {
        terminal_print(1, mapBorderY - 7, "Забор деревянный.");
        terminal_print(1, mapBorderY - 6, "Добротный.");
      }
      if (GG.explanation_ == 8) {
        terminal_print(1, mapBorderY - 7, "Могила...     ...впервые вижу эти руны...");
        terminal_print(1, mapBorderY - 6, "  ...скорее всего они из Атморы.");
      }
      if (GG.explanation_ == 9) {
        terminal_print(1, mapBorderY - 7, "Вода... Не хочу мокнуть.");
        terminal_print(1, mapBorderY - 6, "  Я туда не полезу");
      }
    }
  }
}
