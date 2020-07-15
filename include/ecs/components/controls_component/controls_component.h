//
// Created by vydra on 7/15/19.
//

#ifndef TESROUGEFALKREATH_CODE_HEADERS_CONTROLCOMPONENTS_INPUTKEY_H_
#define TESROUGEFALKREATH_CODE_HEADERS_CONTROLCOMPONENTS_INPUTKEY_H_

#include <BearLibTerminal.h>

class controls_component {
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
    explicit controls_component() {}

    explicit controls_component(controls_component &old) {
        is_enter_ = old.is_enter_;
        is_exit_ = old.is_exit_;
        is_locate_right_ = old.is_locate_right_;
        is_locate_left_ = old.is_locate_left_;
        is_locate_up_ = old.is_locate_up_;
        is_locate_down_ = old.is_locate_down_;
        is_ctrl_button_ = old.is_ctrl_button_;
        is_alt_button_ = old.is_alt_button_;
        is_esc_button_ = old.is_esc_button_;
        is_i_button_ = old.is_i_button_;
        is_e_button_ = old.is_e_button_;
        is_q_button_ = old.is_q_button_;
        is_w_button_ = old.is_w_button_;
        is_a_button_ = old.is_a_button_;
        is_s_button_ = old.is_s_button_;
        is_d_button_ = old.is_d_button_;
        is_f_button_ = old.is_f_button_;
        is_o_button_ = old.is_o_button_;
        is_p_button_ = old.is_p_button_;
        is_m_button_ = old.is_m_button_;
    }

    ~controls_component() {}

    controls_component &operator=(controls_component &old) {
        if (this != &old) {
            is_enter_ = old.is_enter_;
            is_exit_ = old.is_exit_;
            is_locate_right_ = old.is_locate_right_;
            is_locate_left_ = old.is_locate_left_;
            is_locate_up_ = old.is_locate_up_;
            is_locate_down_ = old.is_locate_down_;
            is_ctrl_button_ = old.is_ctrl_button_;
            is_alt_button_ = old.is_alt_button_;
            is_esc_button_ = old.is_esc_button_;
            is_i_button_ = old.is_i_button_;
            is_e_button_ = old.is_e_button_;
            is_q_button_ = old.is_q_button_;
            is_w_button_ = old.is_w_button_;
            is_a_button_ = old.is_a_button_;
            is_s_button_ = old.is_s_button_;
            is_d_button_ = old.is_d_button_;
            is_f_button_ = old.is_f_button_;
            is_o_button_ = old.is_o_button_;
            is_p_button_ = old.is_p_button_;
            is_m_button_ = old.is_m_button_;
        }
        return *this;
    }

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
