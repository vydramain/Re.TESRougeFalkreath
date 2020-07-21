//
// Created by vydra on 7/15/19.
//

#ifndef TESROUGEFALKREATH_CODE_HEADERS_CONTROLCOMPONENTS_INPUTKEY_H_
#define TESROUGEFALKREATH_CODE_HEADERS_CONTROLCOMPONENTS_INPUTKEY_H_

#include <BearLibTerminal.h>

class Controls {
private:
    bool is_enter_ = false;
    bool is_exit_ = false;
    bool is_locate_right_ = false;
    bool is_locate_left_ = false;
    bool is_locate_up_ = false;
    bool is_locate_down_ = false;
    bool is_ctrl_button_ = false;
    bool is_alt_button_ = false;
    bool is_esc_button_ = false;
    bool is_i_button_ = false;
    bool is_e_button_ = false;
    bool is_q_button_ = false;
    bool is_w_button_ = false;
    bool is_a_button_ = false;
    bool is_s_button_ = false;
    bool is_d_button_ = false;
    bool is_f_button_ = false;
    bool is_o_button_ = false;
    bool is_p_button_ = false;
    bool is_m_button_ = false;

public:
    explicit Controls() = default;
    ~Controls() = default;

    bool is_enter() const;
    bool is_exit() const;
    bool is_right() const;
    bool is_left() const;
    bool is_down() const;
    bool is_up() const;
    bool is_button_esc() const;
    bool is_button_alt() const;
    bool is_button_ctrl() const;
    bool is_button_q() const;
    bool is_button_w() const;
    bool is_button_e() const;
    bool is_button_i() const;
    bool is_button_o() const;
    bool is_button_p() const;
    bool is_button_a() const;
    bool is_button_s() const;
    bool is_button_d() const;
    bool is_button_f() const;
    bool is_button_m() const;

    void update();
};

#endif  // TESROUGEFALKREATH_CODE_HEADERS_CONTROLCOMPONENTS_INPUTKEY_H_
