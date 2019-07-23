
#include <BearLibTerminal.h>
#include "./inputKey.h"
#include "./Render.h"

unsigned headMenu();

int main() {
  Render render;
  unsigned gameStatus;
  gameStatus= headMenu();

  if(gameStatus== 1){
      Maps map(0);
      inputKey inputKey;
      player GG(inputKey, 30, 20);
      hud HUD;
    render.goRender(map, GG, HUD);
      while(true){
        terminal_refresh();
        inputKey.Update();
        if(inputKey.IsExit()){
          break;
        }
      }

  } else{
    if(gameStatus== 2){
      return 0;
    }
  }
}










bool menuChoiser(unsigned int &nonshoise){
  inputKey InputKey;
  InputKey.Update();
  if (InputKey.IsUp() && nonshoise > 1) {
    nonshoise--;
  } else {
    if (InputKey.IsDown() && nonshoise < 2) {
      nonshoise++;
    }
  }
  if (InputKey.IsEnter()) {
    return true;
  } else {
    return false;
  }
}

unsigned headMenu(){
  bool IsGo(false);
  unsigned nonchoise(0);  // 0 - Процесс выбора 1 - Новая игра 2 - Выход

  terminal_open();
  terminal_set("window: title='TES Falkreath', size=80x40; font: ./Fonts/Ubuntu-C.ttf, size=12");
  terminal_refresh();

  while (IsGo == false) {
    terminal_clear();
    IsGo = menuChoiser(nonchoise);

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