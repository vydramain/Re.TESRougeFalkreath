//
// Created by vydra on 7/15/19.
//

#include "ecs/systems/controls_system/controls.h"

bool controls::is_enter() const {
    return is_enter_;
}

bool controls::is_exit() const {
    return is_exit_;
}

bool controls::is_right() const {
    return is_locate_right_;
}

bool controls::is_left() const {
    return is_locate_left_;
}

bool controls::is_down() const {
    return is_locate_down_;
}

bool controls::is_up() const {
    return is_locate_up_;
}

bool controls::is_button_esc() const {
    return is_esc_button_;
}

bool controls::is_button_alt() const {
    return is_alt_button_;
}

bool controls::is_button_ctrl() const {
    return is_ctrl_button_;
}

bool controls::is_button_q() const {
    return is_q_button_;
}

bool controls::is_button_w() const {
    return is_w_button_;
}

bool controls::is_button_e() const {
    return is_e_button_;
}

bool controls::is_button_i() const {
    return is_i_button_;
}

bool controls::is_button_o() const {
    return is_o_button_;
}

bool controls::is_button_p() const {
    return is_p_button_;
}

bool controls::is_button_a() const {
    return is_a_button_;
}

bool controls::is_button_s() const {
    return is_s_button_;
}

bool controls::is_button_d() const {
    return is_d_button_;
}

bool controls::is_button_f() const {
    return is_f_button_;
}

bool controls::is_button_m() const {
    return is_m_button_;
}

void controls::update() {
    is_enter_ = false;
    is_exit_ = false;
    is_locate_right_ = false;
    is_locate_left_ = false;
    is_locate_up_ = false;
    is_locate_down_ = false;
    is_ctrl_button_ = false;
    is_alt_button_ = false;
    is_esc_button_ = false;
    is_i_button_ = false;
    is_e_button_ = false;
    is_q_button_ = false;
    is_w_button_ = false;
    is_a_button_ = false;
    is_s_button_ = false;
    is_d_button_ = false;
    is_f_button_ = false;
    is_o_button_ = false;
    is_p_button_ = false;
    is_m_button_ = false;

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
    if (key == TK_CONTROL) {
        is_ctrl_button_ = true;
    }
    if (key == TK_ALT) {
        is_alt_button_ = true;
    }
    if (key == TK_Q) {
        is_q_button_ = true;
    }
    if (key == TK_W) {
        is_w_button_ = true;
    }
    if (key == TK_E) {
        is_e_button_ = true;
    }
    if (key == TK_I) {
        is_i_button_ = true;
    }
    if (key == TK_O) {
        is_o_button_ = true;
    }
    if (key == TK_P) {
        is_p_button_ = true;
    }
    if (key == TK_A) {
        is_a_button_ = true;
    }
    if (key == TK_S) {
        is_s_button_ = true;
    }
    if (key == TK_D) {
        is_d_button_ = true;
    }
    if (key == TK_F) {
        is_f_button_ = true;
    }
    if (key == TK_M) {
        is_m_button_ = true;
    }
}
