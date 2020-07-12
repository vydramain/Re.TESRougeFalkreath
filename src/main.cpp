#include "BearLibTerminal.h"

#include "components/render_component/main_menu_render/main_menu_render.h"

int main() {
    auto *render = new main_menu_render();
    render->render();
    while (terminal_read() != TK_CLOSE);
    delete render;

    return 0;
}