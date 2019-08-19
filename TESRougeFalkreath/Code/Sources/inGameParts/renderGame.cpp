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
  return 0;
}

bool renderGame::mainMenu(unsigned highLight) {
  const char Title[26] = {"Главное меню:"};
  const char* Puncts[4] = {"Новая игра", "Загрузить игру", "Конфигурация", "Выход"};
  unsigned Pincts(4);
  return viewChoise(Title, Puncts, Pincts, highLight, 0, 0, 99, 39);
}