//
// Created by vydra on 7/23/19.
//

#include "../Headers/renderGame.h"

void renderGame::goRender() {}

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
  if ((InputKey.IsEnter() && nonshoise != 0) || InputKey.IsExit()) {
    return true;
  } else {
    return false;
  }
}

unsigned renderGame::headMenu() {
  bool IsGo(false);
  unsigned nonchoise(0);  // 0 - Процесс выбора 1 - Новая игра 2 - Выход

  terminal_open();
  terminal_set("window: title='TES Falkreath', size=20x26; font: ./Fonts/Ubuntu-C.ttf, size=12");
  terminal_refresh();

  while (IsGo == false) {
    terminal_clear();
    IsGo = menuChoiser(nonchoise, 2);
    if (nonchoise == 1) {
      terminal_print(1, 12, "--> Новая Игра <--");
      terminal_print(1, 13, "      Выход");
    } else {
      if (nonchoise == 2) {
        terminal_print(1, 12, "    Новая Игра");
        terminal_print(1, 13, "  --> Выход <--");
      } else {
        terminal_print(5, 12, "Новая Игра");
        terminal_print(5, 13, "  Выход");
      }
    }
    terminal_refresh();
  }
  terminal_close();
  return nonchoise;
}

bool renderGame::inputQuestion(const char *zagolovok, char *GGName) {
  terminal_clear();
  terminal_print(50, 20, zagolovok);
  terminal_refresh();
  terminal_read_str(50, 21, GGName, 12);
  return true;
}

unsigned renderGame::inputChoose(const char **listMenu, const unsigned &menuPoint, const char *zagolovok) {
  bool IsGo(false);
  unsigned choise(0);
  do {
    terminal_clear();
    terminal_print(50, 14, zagolovok);
    for (unsigned i = 0; i < menuPoint; i++) {
      terminal_print(50, 16 + i, listMenu[i]);
      if (i == choise) {
        terminal_print(46, 17 + i, "--> ");
      }
    }
    terminal_refresh();
    IsGo = menuChoiser(choise, 10);
  } while (IsGo == false);
  return choise;
}
