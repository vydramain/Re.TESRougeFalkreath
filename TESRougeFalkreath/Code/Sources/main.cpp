
#include <BearLibTerminal.h>
#include "../Headers/logicParts/inputKey.h"
#include "./inGameLogic.h"
#include "./renderGame.h"

unsigned headMenu();

int main() {
  inputKey InputKey;
  unsigned gameStatus;
  gameStatus = headMenu();
  inGameLogic core(InputKey);

  if (gameStatus == 1) {  //Старт игры
    core.inGameFT();

  } else {
    if (gameStatus == 2) {
      return 0;
    }
  }
}

bool menuChoiser(unsigned int &nonshoise) {
  inputKey InputKey;
  InputKey.Update();
  if (InputKey.IsUp() && nonshoise > 1) {
    nonshoise--;
  } else {
    if (InputKey.IsDown() && nonshoise < 2) {
      nonshoise++;
    }
  }
  if ((InputKey.IsButtonE() && nonshoise != 0) || InputKey.IsExit()) {
    return true;
  } else {
    return false;
  }
}

unsigned headMenu() {
  bool IsGo(false);
  unsigned nonchoise(0);  // 0 - Процесс выбора 1 - Новая игра 2 - Выход

  terminal_open();
  terminal_set("window: title='TES Falkreath', size=80x40; font: ./Fonts/Ubuntu-C.ttf, size=12");
  terminal_refresh();

  while (IsGo == false) {
    terminal_clear();
    IsGo = menuChoiser(nonchoise);
    terminal_print(50, 1, "Перемещение: Стрелки");
    terminal_print(50, 2, "Действие: Клавиша У");

    if (nonchoise == 1) {
      terminal_print(16, 20, "--> Новая Игра <--");
      terminal_print(16, 21, "      Выход");
    } else {
      if (nonchoise == 2) {
        terminal_print(16, 20, "    Новая Игра");
        terminal_print(16, 21, "  --> Выход <--");
      } else {
        terminal_print(20, 20, "Новая Игра");
        terminal_print(20, 21, "  Выход");
      }
    }
    terminal_refresh();
  }
  return nonchoise;
}