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

void renderGame::goRender(const map &currentMap, const player &GG, const npcs &NPCS) {
  showMap(currentMap, GG.mapX_, GG.mapY_);
  showNPCS(NPCS, GG.mapX_, GG.mapY_);
  showPlayer(GG);
  showHud(currentMap, GG, NPCS);
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
  terminal_read_str(1 + zagolovokSize, 1, GGName, 10);
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
  terminal_color(0xFFFFFFFF);
  if (GG.status_ == 2) {
    terminal_color(0xff00ff00);
  }
  terminal_put_ext(GG.screenX_, GG.screenY_, 0, -1, GG.naked);
}

void renderGame::showNPCS(const npcs &NPC, int xPlayer, int yPlayer) {
  terminal_layer(9);
  for (int ii(0); ii < mapBorderY; ii++) {
    for (int i(0); i < mapBorderX; i++) {
      if (yPlayer - 20 + ii == NPC.mapY_ && xPlayer - 30 + i == NPC.mapX_) {
        switch (NPC.status_) {
          case 1: {
            terminal_color(0xffeeee00);
            terminal_put_ext(i, ii, 0, 0, NPC.naked);
            break;
          }
          case 2: {
            terminal_color(0xffe00000);
            terminal_put_ext(xPlayer - 30 + i, yPlayer - 20 + ii, 0, 0, NPC.naked);
            break;
          }
          case 3: {
            // terminal_color(0xff00ffff);
            // terminal_put_ext(xPlayer - 30 + i, yPlayer - 20 + ii, 0, 0, NPC.naked);
          }
          case 4: {
            // terminal_color(0xff6060ff);
            // terminal_put_ext(xPlayer - 30 + i, yPlayer - 20 + ii, 0, 0, NPC.naked);
          }
          default: {
            terminal_color(0xff222222);
            terminal_put_ext(xPlayer - 30 + i, yPlayer - 20 + ii, 0, 0, NPC.naked);
          }
        }
      }
    }
  }
}

void renderGame::showHud(const map &CurrentMap, const player &GG, npcs NPC) {
  terminal_layer(10);
  terminal_color(0xffffffff);
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
  switch (GG.status_) {
    case 1:
      terminal_print(mapBorderX + 1 + 8, 3, "Здоров");
      break;
    case 2:
      terminal_print(mapBorderX + 1 + 8, 3, "Спрятался");
      break;
    default:
      terminal_print(mapBorderX + 1 + 8, 3, "Мёртв");
      break;
  }

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

  terminal_print(mapBorderX + 1, 11, "Задания:");
  if (GG.quest == 1) {
    terminal_print(mapBorderX + 1, 13, "Найти пасхалку.");
  }
  terminal_print(mapBorderX + 1, 20, "Экипировка:");
  terminal_print(mapBorderX + 1, 26, "Сумка:");

  if (GG.confirmAsk_ || GG.explanationAsk_) {
    showDialog(CurrentMap, GG, NPC);
  }
}

unsigned renderGame::npcDialog(npcs NPC) {
  NPC.makeDiaog(4);
  NPC.addDialog("Приветствую тебя, кем ты не был! Я - Асгольд!", "Я самый первый хоть на что-нибудь способный NPC!", 45, 48, 0);
  NPC.addDialog("Ты находшься в Фолкрите!", "Славном городе на юго-западе Скайрима!", 24, 38, 1);
  NPC.addDialog("Впринципе занятся тут толком то и не чем...", "В Восточный Лес ходить не советую... Там АБОРТ обитает.", 43, 55, 2);
  NPC.addDialog("Но можешь погулять по Фолкриту и посмотреть, что тут есть!", "Пасхалка тут хоть и глупая, но есть.^^", 58, 38, 3);
  NPC.makeAnswer(4, 2);
  NPC.addAnswer("Где я?", 6, 0, 0);
  NPC.addAnswer("-закончить диалог-", 18, 0, 1);
  NPC.addAnswer("Есть тут чем заняться?", 22, 1, 0);
  NPC.addAnswer("-закончить диалог-", 18, 1, 1);
  NPC.addAnswer("Печально...", 11, 2, 0);
  NPC.addAnswer("-закончить диалог-", 18, 2, 1);
  NPC.addAnswer("Поищу. Если найду. напишу о ней в обратной связи", 48, 3, 0);
  NPC.addAnswer("-закончить диалог-", 18, 3, 1);

  bool IsGo(false);
  unsigned i = 0, choise = 0;
  bool endDia = true;
  terminal_clear_area(0, mapBorderY - 9, mapBorderX, mapBorderY);
  while (endDia && (i < NPC.countAnswers_ && i < NPC.countPhrases_)) {  //  Объединить в  одну функцию создание диалогов
    terminal_print(1, mapBorderY - 7, NPC.npcPhrases_[i][0]);  // Запихать диалоги в Файл и читать их из файла!
    terminal_print(1, mapBorderY - 6, NPC.npcPhrases_[i][1]);

    do {
      terminal_clear_area(0, mapBorderY - 4, mapBorderX, mapBorderY);
      for (unsigned I = 0; I < NPC.countVariables_; I++) {
        terminal_print(10, mapBorderY - 4 + I, NPC.npcAnswers_[i][I]);
        if (I == choise - 1) {
          terminal_print(1, mapBorderY - 4 + I, "--> ");
        }
      }
      terminal_refresh();
      IsGo = menuChoiser(choise, 2);
    } while (IsGo == false);

    if (0 == choise - 1) {
      i++;
    } else {
      if (1 == choise - 1) {
        endDia = false;
      }
    }
  }

  NPC.elimDialog();
  NPC.elimAnswer();

  if (i == NPC.countPhrases_) {
    return 1;
  } else {
    return 0;
  }
}

void renderGame::showDialog(const map &CurrentMap, const player &GG, npcs NPC) {
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
            if (GG.question_ == 5) {
              questRender = npcDialog(NPC);
              terminal_clear_area(0, mapBorderY - 9, mapBorderX, mapBorderY);
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
      if (GG.explanation_ == 10) {
        terminal_print(1, mapBorderY - 7, "Это... ");
        terminal_printf(8, mapBorderY - 7, NPC.npcName_);
        terminal_print(1, mapBorderY - 6, "Он ");
        switch (NPC.npcNation_) {
          case 1: {
            terminal_print(4, mapBorderY - 6, "Норд");
            break;
          }
          case 2: {
            terminal_print(4, mapBorderY - 6, "Бретонец");
            break;
          }
          case 3: {
            terminal_print(4, mapBorderY - 6, "Редгард");
            break;
          }
          case 4: {
            terminal_print(4, mapBorderY - 6, "Имперец");
            break;
          }
          case 5: {
            terminal_print(4, mapBorderY - 6, "Высокий Эльф");
            break;
          }
          case 6: {
            terminal_print(4, mapBorderY - 6, "Тёмный Эльф");
            break;
          }
          case 7: {
            terminal_print(4, mapBorderY - 6, "Лесной Эльф");
            break;
          }
          case 8: {
            terminal_print(4, mapBorderY - 6, "Орк");
            break;
          }
          case 9: {
            terminal_print(4, mapBorderY - 6, "Аргонианин");
            break;
          }
          case 10: {
            terminal_print(4, mapBorderY - 6, "Каджит");
            break;
          }
          default: {
            terminal_print(4, mapBorderY - 6, " ");
            break;
          }
        }
      }
    }
  }
}
