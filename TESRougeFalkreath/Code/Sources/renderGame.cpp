//
// Created by vydra on 7/23/19.
//

#include "../Headers/renderGame.h"

renderGame::renderGame(bool gameMode) {
  if (gameMode) {
    terminal_open();
    terminal_set("window: title='TES Falkreath', fullscreen: true, size=100x40; font: ./Fonts/Ubuntu-C.ttf, size=12");
    terminal_refresh();
  } else {
    terminal_open();
    terminal_set("window: title='TES Falkreath', size=20x26; font: ./Fonts/Ubuntu-C.ttf, size=12");
    terminal_refresh();
  }
}

renderGame::~renderGame() {
  terminal_close();
}

void renderGame::goRender(const map &currentMap, const player &GG) {
  showMap(currentMap, GG.mapX_, GG.mapY_);
  showPlayer(GG);
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
    if (nonchoise == 1) {
      terminal_print(1, 8, "--> Новая Игра <--");
      terminal_print(4, 9, "  Загрузка  ");
      terminal_print(4, 10, " Сохранения ");
      terminal_print(4, 11, "Конфигурация");
      terminal_print(4, 12, " Конец Игры ");
    } else {
      if (nonchoise == 2) {
        terminal_print(4, 8, " Новая Игра ");
        terminal_print(0, 9, "--> (неработает) <--");
        terminal_print(4, 10, " Сохранения ");
        terminal_print(4, 11, "Конфигурация");
        terminal_print(4, 12, " Конец Игры ");
      } else {
        if (nonchoise == 3) {
          terminal_print(4, 8, " Новая Игра ");
          terminal_print(4, 9, "  Загрузка  ");
          terminal_print(0, 10, "--> (неработает) <--");
          terminal_print(4, 11, "Конфигурация");
          terminal_print(4, 12, " Конец Игры ");
        } else {
          if (nonchoise == 4) {
            terminal_print(4, 8, " Новая Игра ");
            terminal_print(4, 9, "  Загрузка  ");
            terminal_print(4, 10, " Сохранения ");
            terminal_print(0, 11, "--> (неработает) <--");
            terminal_print(4, 12, " Конец Игры ");
          } else {
            if (nonchoise == 5) {
              terminal_print(4, 8, " Новая Игра ");
              terminal_print(4, 9, "  Загрузка  ");
              terminal_print(4, 10, " Сохранения ");
              terminal_print(4, 11, "Конфигурация");
              terminal_print(1, 12, "--> Конец Игры <--");
            } else {
              terminal_print(4, 8, " Новая Игра ");
              terminal_print(4, 9, "  Загрузка  ");
              terminal_print(4, 10, " Сохранения ");
              terminal_print(4, 11, "Конфигурация");
              terminal_print(4, 12, " Конец Игры ");
            }
          }
        }
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
  if (mapSym == '~') {
    terminal_color(0xcc00ffff);
  } else {
    if (mapSym == ';' || mapSym == '+' || mapSym == '-' || mapSym == '?' || mapSym == ':' || mapSym == 'J' || mapSym == '`') {
      terminal_color(0xff26cf26);
    } else {
      if (mapSym == ']' || mapSym == '_') {
        terminal_color(0xff7f7f7f);
      } else {
        if (mapSym == 'W' || mapSym == 'w' || mapSym == 'V') {
          terminal_color(0xffe3c347);
        } else {
          if (mapSym == '"' || mapSym == '|' || mapSym == '=' || mapSym == '>' || mapSym == '^' || mapSym == 'v' || mapSym == '<') {
            terminal_color(0xffba7300);
          } else {
            if (mapSym == '#') {
              terminal_color(0xff666666);
            } else {
              if (mapSym == 'L') {
                terminal_color(0xffabff00);
              } else {
                if (mapSym == 'A') {
                  terminal_color(0xccFF0000);
                } else {
                  if (mapSym == 't') {
                    terminal_color(0xffb2b2b2);
                  } else {
                    terminal_color(0xff4c4c4c);
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}

void renderGame::showMap(const map &currentLocation, int xPlayer, int yPlayer) {
  for (int ii(0); ii < 40; ii++) {
    for (int i(0); i < 66; i++) {
      terminal_color(0xaaffffff);
      if (yPlayer - 20 + ii < 0) {
        terminal_put(i, ii, ' ');
      } else {
        if (xPlayer - 30 + i < 0) {
          terminal_put(i, ii, ' ');
        } else {
          if (yPlayer - 20 + ii >= currentLocation.mapYSize_) {
            terminal_put(i, ii, ' ');
          } else {
            if (xPlayer - 30 + i >= currentLocation.mapXSize_ - 1) {
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
  terminal_color(0xffffffff);
  terminal_put_ext(GG.screenX_, GG.screenY_, 0, -1, GG.naked);
}
