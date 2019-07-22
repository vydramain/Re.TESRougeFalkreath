//
// Created by vyrda on 7/22/19.
//
#include <BearLibTerminal.h>
#include "./inputKey.h"

bool menuChoiser(unsigned int &nonshoise){
  inputKey InputKey;
  InputKey.Update();
  if (InputKey.IsUp() && nonshoise < 2) {
    nonshoise--;
  } else {
    if (InputKey.IsDown() && nonshoise > 1) {
      nonshoise++;
    }
  }
  if (InputKey.IsEnter()) {
    return true;
  } else {
    return false;
  }
}

unsigned mainMenu() {
  bool IsGo(false);
  unsigned nonchoise(0);  // 0 - Процесс выбора 1 - Новая игра 2 - Выход

  terminal_open();
  terminal_set("window: title='TES Falkreath', size=80x40; font: ./Fonts/Ubuntu-C.ttf, size=12");
  terminal_refresh();

  while (IsGo == false) {
    terminal_clear();
    IsGo = menuChoiser(nonchoise);

    if (nonchoise == 1) {
      terminal_print(20, 20, "Новая Игра <--");
      terminal_print(20, 21, "  Выход");
    } else {
      if (nonchoise == 2) {
        terminal_print(20, 20, "Новая Игра");
        terminal_print(20, 21, "  Выход <--");
      } else {
        terminal_print(20, 20, "Новая Игра");
        terminal_print(20, 21, "  Выход");
      }
    }
    terminal_refresh();
  }
  return nonchoise;
}