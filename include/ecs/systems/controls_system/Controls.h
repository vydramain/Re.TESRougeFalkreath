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
    bool is_esc_button_ = false;

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

    void update();
};

#endif  // TESROUGEFALKREATH_CODE_HEADERS_CONTROLCOMPONENTS_INPUTKEY_H_
