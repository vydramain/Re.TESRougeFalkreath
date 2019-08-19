#include "inGameParts/renderGame.h"

renderGame::renderGame() {
  terminal_open();
  terminal_set("window: title='TES Falkreath', cellsize=8x15, size=100x40, fullscreen=true; font: ./Fonts/Ubuntu-C.ttf, size=12");
  terminal_refresh();
}

renderGame::renderGame(unsigned gameMode) {
  switch (gameMode) {
    case 1: {
      terminal_open();
      terminal_set("window: title='TES Falkreath', cellsize=8x15, size=100x40, fullscreen=true; font: ./Fonts/Ubuntu-C.ttf, size=12");
      terminal_refresh();
      break;
    }
    default: {
      terminal_open();
      terminal_set("window: title='TES Falkreath', cellsize=8x15, size=100x40, fullscreen=true; font: ./Fonts/Ubuntu-C.ttf, size=12");
      terminal_refresh();
      terminal_print(0, 0, "Ошибка_renderGame:_Нестандарная_gameMode_переменная_");
      break;
    }
  }
}

renderGame::~renderGame() {
  terminal_close();
}

void renderGame::clearALL() {
  for (unsigned i(0); i < 20; i++) {
    terminal_layer(i);
    terminal_clear();
  }
}

bool renderGame::viewWord(const char* Request, char* Word, unsigned RequestChars, unsigned WordChars, unsigned inX, unsigned inY,
                          unsigned outX, unsigned outY) {
  terminal_layer(HUDLAYER);
  for (unsigned ii(0); ii < (outY - inY); ii++) {
    for (unsigned i(0); i < (outX - inX); i++) {
      terminal_put(inX + i, inY + ii, ' ');
    }
  }

  for (unsigned ii(0); ii < (outY - inY); ii++) {
    terminal_put(inX, inY + 1 + ii, '|');
    terminal_put(outX, inY + ii, '|');
  }
  for (unsigned i(0); i < (outX - inX); i++) {
    terminal_put(inX + i, inY, '-');
    terminal_put(inX + 1 + i, outY, '-');
  }

  terminal_print(inX + 2, inY + 2, Request);
  terminal_read_str(2 + RequestChars, 2, Word, WordChars);
  return true;
}

bool renderGame::viewChoise(const char* title, const char** punctsChoise, unsigned punctsCount, unsigned punctsHighlighted, unsigned inX,
                            unsigned inY, unsigned outX, unsigned outY) {
  terminal_layer(HUDLAYER);
  for (unsigned ii(0); ii < (outY - inY); ii++) {
    for (unsigned i(0); i < (outX - inX); i++) {
      terminal_put(inX + i, inY + ii, ' ');
    }
  }

  for (unsigned ii(0); ii < (outY - inY); ii++) {
    terminal_put(inX, inY + 1 + ii, '|');
    terminal_put(outX, inY + ii, '|');
  }
  for (unsigned i(0); i < (outX - inX); i++) {
    terminal_put(inX + i, inY, '-');
    terminal_put(inX + 1 + i, outY, '-');
  }

  terminal_print(inX + 6, inY + 2, title);
  for (unsigned i(1); i < punctsCount + 1; i++) {
    if (punctsHighlighted == i) {
      terminal_print(inX + 2, inY + 3 + i, "-->");
    }
    terminal_print(inX + 6, inY + 3 + i, punctsChoise[i - 1]);
  }
  return false;
}

bool renderGame::mainMenu(unsigned highLight) {
  const char Title[26] = {"Главное меню:"};
  const char* Puncts[4] = {"Новая игра", "Загрузить игру", "Конфигурация", "Выход"};
  unsigned Pincts(4);
  return viewChoise(Title, Puncts, Pincts, highLight, 0, 0, 99, 39);
}

bool renderGame::raceMenu(unsigned highLight) {
  const char Title[26] = {"Выбери Расу: "};
  const char* Puncts[10] = {"Норд",        "Бретон",      "Редгард", "Имперец",    "Высокий эльф",
                            "Тёмный эльф", "Лесной эльф", "Орк",     "Аргонианин", "Каджит"};
  unsigned Pincts(10);
  return viewChoise(Title, Puncts, Pincts, highLight, 0, 0, 99, 39);
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

void renderGame::showArea(logicComponents* COMPONENTS) {
  unsigned mapX, mapY;
  playMap* AREA = COMPONENTS->secret();
  AREA->viewSize(mapX, mapY);
  unsigned playerX, playerY;
  COMPONENTS->conditionPlayer(playerX, playerY);
  terminal_layer(1);
  char temp;
  for (unsigned ii(0); ii < mapBorderY_; ii++) {
    for (unsigned i(0); i < mapBorderX_; i++) {
      terminal_color(0xaaffffff);
      if (playerY - 20 + ii <= 0) {
        terminal_put(i, ii, ' ');
      } else {
        if (playerX - 30 + i <= 0) {
          terminal_put(i, ii, ' ');
        } else {
          if (playerY - 20 + ii >= mapY-1) {
            terminal_put(i, ii, ' ');
          } else {
            if (playerX - 30 + i >= mapX-1) {
              terminal_put(i, ii, ' ');
            } else {
              AREA->pullKnot0(playerX - 30 + i, playerY - 20 + ii, temp);
              symColor(temp);
              terminal_put(i, ii, temp);
            }
          }
        }
      }
    }
  }
}

void renderGame::showPlayer(logicComponents* COMPONENTS) {
  char playerName[24];
  unsigned playerX, playerY, playerHP, playerAP, playerMP, playerNationality, playerStatus;
  COMPONENTS->conditionPlayer(playerX, playerY, playerHP, playerAP, playerMP, playerNationality, playerStatus, playerName);
  terminal_layer(1);
  terminal_color(0xFFFFFFFF);
  if (playerStatus == 2) {
    terminal_color(0xff00ff00);
  }
  terminal_put_ext(30, 20, 0, -1, 'i');
}

void renderGame::showHud(logicComponents* COMPONENTS) {
  char playerName[24];
  unsigned playerX, playerY, playerHP, playerAP, playerMP, playerNationality, playerStatus;
  COMPONENTS->conditionPlayer(playerX, playerY, playerHP, playerAP, playerMP, playerNationality, playerStatus, playerName);

  terminal_layer(5);
  terminal_color(0xffffffff);
  for (unsigned i(0); i < mapBorderY_; i++) {
    terminal_print(mapBorderX_, i, "|");
  }

  terminal_print(mapBorderX_ + 1, 9, "________________________________");
  terminal_print(mapBorderX_ + 1, mapBorderY_ - 5, "________________________________");

  terminal_print(mapBorderX_ + 1, 1, "Имя:");
  terminal_print(mapBorderX_ + 1, 2, "Расса:");
  terminal_print(mapBorderX_ + 1, 3, "Статус:");
  terminal_print(mapBorderX_ + 1, 4, "ОЗ:");
  terminal_print(mapBorderX_ + 1, 5, "ОД:");
  terminal_print(mapBorderX_ + 1, 6, "OМ:");
  terminal_print(mapBorderX_ + 1, 11, "Задания:");
  terminal_print(mapBorderX_ + 1, 20, "Экипировка:");
  terminal_print(mapBorderX_ + 1, 26, "Сумка:");

  terminal_print(mapBorderX_ + 1 + 5, 1, playerName);
  switch (playerNationality) {
    case 1: {
      terminal_print(mapBorderX_ + 1 + 7, 2, "Норд");
      break;
    }
    case 2: {
      terminal_print(mapBorderX_ + 1 + 7, 2, "Бретонец");
      break;
    }
    case 3: {
      terminal_print(mapBorderX_ + 1 + 7, 2, "Редгард");
      break;
    }
    case 4: {
      terminal_print(mapBorderX_ + 1 + 7, 2, "Имперец");
      break;
    }
    case 5: {
      terminal_print(mapBorderX_ + 1 + 7, 2, "Высокий Эльф");
      break;
    }
    case 6: {
      terminal_print(mapBorderX_ + 1 + 7, 2, "Тёмный Эльф");
      break;
    }
    case 7: {
      terminal_print(mapBorderX_ + 1 + 7, 2, "Лесной Эльф");
      break;
    }
    case 8: {
      terminal_print(mapBorderX_ + 1 + 7, 2, "Орк");
      break;
    }
    case 9: {
      terminal_print(mapBorderX_ + 1 + 7, 2, "Аргонианин");
      break;
    }
    case 10: {
      terminal_print(mapBorderX_ + 1 + 7, 2, "Каджит");
      break;
    }
    default: {
      terminal_print(mapBorderX_ + 1 + 7, 2, " ");
      break;
    }
  }

  switch (playerStatus) {
    case 1:
      terminal_print(mapBorderX_ + 1 + 8, 3, "Здоров");
      break;
    case 2:
      terminal_print(mapBorderX_ + 1 + 8, 3, "Спрятался");
      break;
    default:
      terminal_print(mapBorderX_ + 1 + 8, 3, "Мёртв");
      break;
  }

  char hp[5], mp[5], ap[5];
  sprintf(hp, "%d", playerHP);
  sprintf(ap, "%d", playerAP);
  sprintf(mp, "%d", playerMP);
  terminal_print(mapBorderX_ + 1 + 5, 4, hp);
  terminal_print(mapBorderX_ + 1 + 5, 5, ap);
  terminal_print(mapBorderX_ + 1 + 5, 6, mp);

  terminal_print(mapBorderX_ + 1, 9, "________________________________");
  terminal_print(mapBorderX_ + 1, mapBorderY_ - 5, "________________________________");

  terminal_print(mapBorderX_ + 1, 11, "Задания:");
  terminal_print(mapBorderX_ + 1, 20, "Экипировка:");
  terminal_print(mapBorderX_ + 1, 26, "Сумка:");
}

bool renderGame::Update(logicComponents* COMPONENTS) {
  clearALL();
  showArea(COMPONENTS);
  showPlayer(COMPONENTS);
  showHud(COMPONENTS);

  terminal_refresh();

  return false;
}