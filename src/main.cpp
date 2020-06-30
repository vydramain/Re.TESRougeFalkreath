#include <iostream>
#include "BearLibTerminal.h"

int main() {
    terminal_open();
    terminal_set("window: title='re:TESFalkreath', cellsize=8x15, size=100x40, fullscreen=true");
    terminal_refresh();
    terminal_printf(0, 0, "Dras'kay Nirni!");    // Ta'agra
    terminal_refresh();

    while (terminal_read() != TK_CLOSE);

    terminal_close();
    return 0;
}