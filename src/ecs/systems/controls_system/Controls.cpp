//
// Created by vydra on 7/15/19.
//

#include "ecs/systems/controls_system/Controls.h"

bool Controls::is_enter() const {
    return is_enter_;
}

bool Controls::is_exit() const {
    return is_exit_;
}

bool Controls::is_right() const {
    return is_locate_right_;
}

bool Controls::is_left() const {
    return is_locate_left_;
}

bool Controls::is_down() const {
    return is_locate_down_;
}

bool Controls::is_up() const {
    return is_locate_up_;
}

bool Controls::is_button_esc() const {
    return is_esc_button_;
}

void Controls::update() {
    is_enter_ = false;
    is_exit_ = false;
    is_locate_right_ = false;
    is_locate_left_ = false;
    is_locate_up_ = false;
    is_locate_down_ = false;
    is_esc_button_ = false;

    auto key = terminal_read();
    if (key == TK_ENTER) {
        is_enter_ = true;
    }
    if (key == TK_CLOSE) {
        is_exit_ = true;
    }
    if (key == TK_UP) {
        is_locate_up_ = true;
    }
    if (key == TK_DOWN) {
        is_locate_down_ = true;
    }
    if (key == TK_LEFT) {
        is_locate_left_ = true;
    }
    if (key == TK_RIGHT) {
        is_locate_right_ = true;
    }
    if (key == TK_ESCAPE) {
        is_esc_button_ = true;
    }
}
