//
// Created by vydra on 7/23/19.
//

#include "../Headers/renderGame.h"

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

void renderGame::clearALL() {
  for (unsigned i(0); i < 20; i++) {
    terminal_layer(i);
    terminal_clear();
  }
}

void renderGame::goRender(const map &currentMap, const player &GG) {
  showMap(currentMap, GG.mapX_, GG.mapY_);
  showPlayer(GG);
  showHud(GG);
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
                    if (mapSym == 'A' || mapSym == 'Y' || mapSym == 'T') {
                      terminal_color(0xffffaaaa);
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
}

void renderGame::showMap(const map &currentLocation, int xPlayer, int yPlayer) {
  terminal_layer(10);
  for (int ii(0); ii < mapBorderY; ii++) {
    for (int i(0); i < mapBorderX; i++) {
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
  terminal_layer(1);
  terminal_color(0xffffffff);
  terminal_put_ext(GG.screenX_, GG.screenY_, 0, -1, GG.naked);
  if (GG.status_ == 1) {
    terminal_layer(2);
    terminal_color(0xffff6666);
    terminal_put_ext(GG.screenX_, GG.screenY_, 0, 2, 'A');
  } else {
    if (GG.status_ == 2) {
      terminal_layer(2);
      terminal_color(0xffff6666);
      terminal_put_ext(GG.screenX_, GG.screenY_, 1, 2, 'Y');
    } else {
      if (GG.status_ == 1) {
        terminal_layer(2);
        terminal_color(0xffff6666);
        terminal_put_ext(GG.screenX_, GG.screenY_, 0, 3, 'T');
      }
    }
  }
  terminal_color(0xffffffff);
}

void renderGame::showHud(const player &GG) {
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

  if (GG.playerNation_ == 1) {
    strcpy(nationality, "Норд");
  } else {
    if (GG.playerNation_ == 2) {
      strcpy(nationality, "Бретонец");
    } else {
      if (GG.playerNation_ == 3) {
        strcpy(nationality, "Редгард");
      } else {
        if (GG.playerNation_ == 4) {
          strcpy(nationality, "Имперец");
        } else {
          if (GG.playerNation_ == 5) {
            strcpy(nationality, "Высокий Эльф");
          } else {
            if (GG.playerNation_ == 6) {
              strcpy(nationality, "Тёмный Эльф");
            } else {
              if (GG.playerNation_ == 7) {
                strcpy(nationality, "Лесной Эльф");
              } else {
                if (GG.playerNation_ == 8) {
                  strcpy(nationality, "Орк");
                } else {
                  if (GG.playerNation_ == 9) {
                    strcpy(nationality, "Аргонианин");
                  } else {
                    if (GG.playerNation_ == 10) {
                      strcpy(nationality, "Каджит");
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

  if (confirmAsk_ || explanationAsk_) {
    showDialog();
  }
}

void renderGame::showDialog() {
  terminal_clear_area(0, mapBorderY - 10, mapBorderX, mapBorderY);
  for (int i(0); i < mapBorderX; i++) {
    terminal_put(i, mapBorderY - 10, '_');
  }
  if (question_ != 0) {
    if (question_ == 1) {
      terminal_print(1, mapBorderY - 7, "Открыть дверь?");
    } else {
      if (question_ == 2) {
        terminal_print(1, mapBorderY - 7, "Спрятаться в зелени?");
      } else {
        if (question_ == 10) {
          terminal_print(1, mapBorderY - 7, "Надеть броню?");
        } else {
          if (question_ == 11) {
            terminal_print(1, mapBorderY - 7, "У тебя уже есть броня! (жадина)");
          }
        }
      }
    }
  } else {
    if (explanation_ != 0) {
      if (explanation_ == 1) {
        terminal_print(1, mapBorderY - 7, "Это дверь.");
        terminal_print(1, mapBorderY - 6, "Похоже, изготовлена из многовековой ели.");
      }
      if (explanation_ == 2) {
        terminal_print(1, mapBorderY - 7, "Это хвойное растение.");
        terminal_print(1, mapBorderY - 6, "Похоже на ель.");
      }
      if (explanation_ == 3) {
        terminal_print(1, mapBorderY - 7, "Камень.");
        terminal_print(1, mapBorderY - 6, "Мне через него не перебраться.");
      }
      if (explanation_ == 4) {
        terminal_print(1, mapBorderY - 7, "Гладкая каменная стена....");
        terminal_print(1, mapBorderY - 6, "          ...из хорошего булыжника.");
      }
      if (explanation_ == 5) {
        terminal_print(1, mapBorderY - 7, "Пшеница... ");
        terminal_print(1, mapBorderY - 6, "Несозревшая...");
      }
      if (explanation_ == 6) {
        terminal_print(1, mapBorderY - 7, "Ствол... ");
        terminal_print(1, mapBorderY - 6, "Просто ствол дерева...");
      }
      if (explanation_ == 7) {
        terminal_print(1, mapBorderY - 7, "Забор деревянный.");
        terminal_print(1, mapBorderY - 6, "Добротный.");
      }
      if (explanation_ == 8) {
        terminal_print(1, mapBorderY - 7, "Могила...     ...впервые вижу эти руны...");
        terminal_print(1, mapBorderY - 6, "  ...скорее всего они из Атморы.");
      }
      if (explanation_ == 9) {
        terminal_print(1, mapBorderY - 7, "Вода... Не хочу мокнуть.");
        terminal_print(1, mapBorderY - 6, "  Я туда не полезу");
      }
    }
  }
}
