//
// Created by vydra on 09.07.2020.
//

#ifndef RE_TESROUGEFALKREATH_HELLO_WORLD_H
#define RE_TESROUGEFALKREATH_HELLO_WORLD_H

void hello_world() {
    terminal_open();
    terminal_set("window: title='re:TESFalkreath', cellsize=8x15, size=100x40, fullscreen=true");
    terminal_refresh();
    terminal_printf(0, 0, "Dras'kay Nirni!");    // Ta'agra
    terminal_refresh();

    while (terminal_read() != TK_CLOSE);

    terminal_close();
}

#endif //RE_TESROUGEFALKREATH_HELLO_WORLD_H
