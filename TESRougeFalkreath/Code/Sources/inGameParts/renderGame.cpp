#include "inGameParts/renderGame.h"

renderGame::renderGame() {
  terminal_open();
  terminal_set("window: title='TES Falkreath', cellsize=8x15, size=100x40, fullscreen=true; font: ./Fonts/Ubuntu-C.ttf, size=12");
  terminal_refresh();

  stepMeter_ = 0;
}

renderGame::renderGame(unsigned gameMode) {
  switch (gameMode) {
    case 1: {
      terminal_open();
      terminal_set("window: title='TES Falkreath', cellsize=12x15, size=100x40, fullscreen=true; font: ./Fonts/Ubuntu-R.ttf, size=12");
      terminal_refresh();

      stepMeter_ = 0;
      break;
    }
    default: {
      terminal_open();
      terminal_set("window: title='TES Falkreath', cellsize=8x15, size=100x40, fullscreen=true; font: ./Fonts/Ubuntu-C.ttf, size=12");
      terminal_refresh();
      terminal_print(0, 0, "Ошибка_renderGame:_Нестандарная_gameMode_переменная_");

      stepMeter_ = 0;
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

void renderGame::clearAREA(unsigned inX, unsigned inY, unsigned outX, unsigned outY) {
  for (unsigned i(0); i < 20; i++) {
    terminal_layer(i);
    terminal_clear_area(inX, inY, outX, outY);
  }
}

bool renderGame::viewPhrase(const char* fstString, const char* scdString, unsigned inX, unsigned inY, unsigned outX, unsigned outY) {
  clearAREA(inX, inY, outX + 1, outY);
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

  terminal_print(inX + 2, inY + 2, fstString);
  terminal_print(inX + 2, inY + 3, scdString);
  return false;
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
  return false;
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

bool renderGame::deathScreen(logicComponents* COMPONENTS) {
  clearALL();
  unsigned playerStatus = COMPONENTS->conditionPlayerSTATUS();
  unsigned playerWallet = COMPONENTS->conditionPlayerWALLET();
  if (playerStatus == 0) {
    viewPhrase("Как это не печально но вы были убиты...", "Может в следующий раз ты поступишь умнее...", 0, 0, 99, 39);
  }
  if (playerStatus == 1) {
    terminal_layer(1);
    viewPhrase("Вы отправились в дальнее путешествие...", "Вы покинули Фолкрит навсегда...", 0, 0, 99, 5);
    viewPhrase("Никто из нынешних жителей Фолкрита никогда не увидит больше вас...", "", 0, 7, 99, 11);
    viewPhrase("Но и вспоминать они вас не будут...", "Никто о вас не знал вас. Вы - очередной безымянный путешественник.", 0, 13, 99, 18);
    if (playerWallet > 60) {
      viewPhrase("Однако, жители после вашего ухода перестали доверять друг другу.",
                 "Никто больше не приветствовал друг друга со счастливой улыбкой.", 0, 20, 99, 25);
      viewPhrase("И особенно не жаловали путешественников...", " ", 0, 27, 99, 31);
    } else {
      if (playerWallet == 0) {
        viewPhrase("Фолкрит остался всё таким же, каким и был до этого...", "Тихим и прекрасным местом...", 0, 20, 99, 25);
        viewPhrase("Зелёной сокровищницей, скрывающей внутри себя хвойные и смолистые драгоценности.", "", 0, 27, 99, 31);
      } else {
        viewPhrase("И вы хорошо знаете удел искателя приключений.", "", 0, 20, 99, 24);
      }
    }
  }
  terminal_refresh();
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
      terminal_color(0xff888800);
      break;
    }
    case '$': {
      terminal_color(0xffffff00);
      break;
    }
    case 'Q': {
      terminal_color(0xff44eedd);
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
  mapX = AREA->viewSizeX();
  mapY = AREA->viewSizeY();
  unsigned playerX, playerY;
  playerX = COMPONENTS->conditionPlayerX();
  playerY = COMPONENTS->conditionPlayerY();
  char temp;
  for (unsigned ii(0); ii < mapBorderY_; ii++) {
    for (unsigned i(0); i < mapBorderX_; i++) {
      terminal_color(0xaaffffff);
      if (playerY - 20 + ii > mapY - 2) {
        terminal_put(i, ii, ' ');
      } else {
        if (playerX - 30 + i > mapX - 2) {
          terminal_put(i, ii, ' ');
        } else {
          terminal_layer(1);
          AREA->pullKnot0(playerX - 30 + i, playerY - 20 + ii, temp);
          symColor(temp);
          terminal_put(i, ii, temp);
          terminal_layer(3);
          AREA->pullKnot3(playerX - 30 + i, playerY - 20 + ii, temp);
          symColor(temp);
          terminal_put(i, ii, temp);
        }
      }
    }
  }
}
void renderGame::showPlayer(logicComponents* COMPONENTS) {
  unsigned playerStatus;
  playerStatus = COMPONENTS->conditionPlayerSTATUS();
  terminal_layer(4);
  terminal_color(0xFFFFFFFF);
  if (playerStatus == 2) {
    terminal_color(0xff00ff00);
  }
  terminal_put_ext(30, 20, 0, -1, 'i');
}

void renderGame::showHud(logicComponents* COMPONENTS) {
  char *playerName = COMPONENTS->conditionPlayerNAME();
  unsigned playerX = COMPONENTS->conditionPlayerX();
  unsigned playerY = COMPONENTS->conditionPlayerY();
  unsigned playerHP = COMPONENTS->conditionPlayerHP();
  unsigned playerAP = COMPONENTS->conditionPlayerAP();
  unsigned playerMP = COMPONENTS->conditionPlayerMP();
  unsigned playerNationality = COMPONENTS->conditionPlayerNATIONALITY();
  unsigned playerStatus = COMPONENTS->conditionPlayerSTATUS();
  unsigned playerWallet = COMPONENTS->conditionPlayerWALLET();
  terminal_layer(5);
  terminal_color(0xffffffff);
  for (unsigned i(0); i < mapBorderY_; i++) {
    terminal_print(mapBorderX_, i, "|");
  }

  terminal_print(mapBorderX_ + 1, 9, "________________________________");
  terminal_print(mapBorderX_ + 1, mapBorderY_ - 5, "________________________________");

  char coorX[5], coorY[5], meter[9];
  terminal_print(mapBorderX_ + 1, mapBorderY_ - 3, "Координаты:");
  snprintf(coorX, (size_t) "%d", "%u", playerX);
  snprintf(coorY, (size_t) "%d", "%u", playerY);
  snprintf(meter, (size_t) "%d", "%u", stepMeter_);
  terminal_print(mapBorderX_ + 1 + 12, mapBorderY_ - 3, coorX);
  terminal_print(mapBorderX_ + 1 + 16, mapBorderY_ - 3, coorY);
  terminal_print(mapBorderX_ + 1, mapBorderY_ - 2, "Действий:");
  terminal_print(mapBorderX_ + 1 + 10, mapBorderY_ - 2, meter);

  terminal_print(mapBorderX_ + 1, 1, "Имя:");
  terminal_print(mapBorderX_ + 1, 2, "Раса:");
  terminal_print(mapBorderX_ + 1, 3, "Статус:");

  char hp[5], mp[5], ap[5];
  snprintf(hp, (size_t) "%d", "%u", playerHP);
  snprintf(ap, (size_t) "%d", "%u", playerAP);
  snprintf(mp, (size_t) "%d", "%u", playerMP);
  terminal_color(0xFFFF4444);
  terminal_print(mapBorderX_ + 1, 4, "ОЗ:");
  terminal_print(mapBorderX_ + 1 + 5, 4, hp);
  terminal_color(0xFF44ff44);
  terminal_print(mapBorderX_ + 1, 5, "ОД:");
  terminal_print(mapBorderX_ + 1 + 5, 5, ap);
  terminal_color(0xFF6666FF);
  terminal_print(mapBorderX_ + 1, 6, "OМ:");
  terminal_print(mapBorderX_ + 1 + 5, 6, mp);

  terminal_color(0xFFFFFFFF);
  terminal_print(mapBorderX_ + 1, 11, "Задания:");
  terminal_print(mapBorderX_ + 1, 20, "Экипировка:");
  terminal_print(mapBorderX_ + 1, 26, "Кошель:");
  char wallet[9];
  snprintf(wallet, (size_t) "%d", "%u", playerWallet);
  terminal_print(mapBorderX_ + 1 + 8, 26, wallet);

  terminal_print(mapBorderX_ + 1, 27, "Сумка:");

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
    case 1: {
      terminal_print(mapBorderX_ + 1 + 8, 3, "Здоров");
      break;
    }
    case 2: {
      terminal_print(mapBorderX_ + 1 + 8, 3, "Спрятался");
      break;
    }
    default: {
      terminal_print(mapBorderX_ + 1 + 8, 3, "Мёртв");
      break;
    }
  }
  if ((oldPlayerX_ != playerX) || (oldPlayerY_ != playerY)) {
    oldPlayerX_ = playerX;
    oldPlayerY_ = playerY;
    stepMeter_++;
  }
}

void renderGame::showLogWindow(logicComponents* COMPONENTS) {
  bool mark = COMPONENTS->conditionLogWindow();
  if (mark) {
    unsigned act = COMPONENTS->conditionOldAct();
    playMap* AREA = COMPONENTS->secret();
    unsigned itemX = COMPONENTS->conditionPlayerX();
    unsigned itemY = COMPONENTS->conditionPlayerY();
    unsigned Course = COMPONENTS->conditionPlayerCOURSE();
    switch (Course) {
      case 0: {
        itemY -= 1;
        break;
      }
      case 1: {
        itemY += 1;
        break;
      }
      case 2: {
        itemX -= 1;
        break;
      }
      case 3: {
        itemX += 1;
        break;
      }
      default: {
        break;
      }
    }

    char lay0;
    AREA->pullKnot0(itemX, itemY, lay0);
    switch (act) {
      case 6: {
        if (lay0 == '#') {
          viewPhrase("Камень... Высокий...", "Я на него не смогу забраться.", 0, 30, 65, 39);
        } else {
          if (lay0 == '<' || lay0 == '>' || lay0 == 'v' || lay0 == '^') {
            viewPhrase("Это дверь.", "Похоже, изготовлена из многовековой ели.", 0, 30, 65, 39);
          } else {
            if (lay0 == ';' || lay0 == '+' || lay0 == '-' || lay0 == '?' || lay0 == ':' || lay0 == 'J' || lay0 == '`' || lay0 == '9' ||
                lay0 == 'x') {
              viewPhrase("Это хвойное растение.", "Похоже на ель.", 0, 30, 65, 39);
            } else {
              if (lay0 == '[' || lay0 == ']' || lay0 == '_') {
                viewPhrase("Гладкая каменная стена....", "          ...из хорошего булыжника.", 0, 30, 65, 39);
              } else {
                if (lay0 == 'L') {
                  viewPhrase("Пшеница...", "Несозревшая", 0, 30, 65, 39);
                } else {
                  if (lay0 == '"' || lay0 == '|' || lay0 == '=') {
                    viewPhrase("Ствол.", "Просто ствол дерева.", 0, 30, 65, 39);
                  } else {
                    if (lay0 == 'W' || lay0 == 'w' || lay0 == 'V') {
                      viewPhrase("Забор деревянный.", "Добротный.", 0, 30, 65, 39);
                    } else {
                      if (lay0 == 't') {
                        viewPhrase("Могила...", "     ...впервые вижу эти руны...", 0, 30, 65, 39);
                      } else {
                        if (lay0 == '~') {
                          viewPhrase("Вода... Не хочу мокнуть.", "  Я туда не полезу", 0, 30, 65, 39);
                        } else {
                          if (lay0 == 'Z') {
                            viewPhrase("Восточные ворота Фолкрита.", "Ворота в Скайрим...", 0, 30, 65, 39);
                          } else {
                            if (lay0 == 'Q') {
                              viewPhrase("Покинуть Фолкрит ради новых приключений?",
                                         "Отправившись однажды, вы больше никогда не сможете вернуться.", 0, 30, 65, 39);
                            } else {
                              if (lay0 != ' ' && lay0 != '.') {
                                viewPhrase("Я не знаю что это...", "Вроде на камень смахивает придорожный.", 0, 30, 65, 39);
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
        }
        break;
      }
      case 5: {
        if (lay0 == '<' || lay0 == '>' || lay0 == 'v' || lay0 == '^') {
          viewPhrase("Открыть дверь?", "", 0, 30, 65, 39);
        }
        if (lay0 == 'Z') {
          viewPhrase("Отправиться  в восточный лес?", "", 0, 30, 65, 39);
        }
        if (lay0 == 'Q') {
          viewPhrase("Покинуть Фолкрит?", " Обратного пути не будет...", 0, 30, 65, 39);
        }
        break;
      }
      default: {
        break;
      }
    }
  }
}

bool renderGame::Update(logicComponents* COMPONENTS) {
  clearALL();
  showArea(COMPONENTS);
  showPlayer(COMPONENTS);
  showHud(COMPONENTS);
  showLogWindow(COMPONENTS);
  terminal_refresh();

  return false;
}
