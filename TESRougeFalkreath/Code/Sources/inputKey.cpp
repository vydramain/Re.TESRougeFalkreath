//
// Created by vydra on 7/15/19.
//

#include "./inputKey.h"

inputKey::inputKey(const inputKey& old) {
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

inputKey& inputKey::operator=(const inputKey& old) {
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

bool inputKey::IsEnter() const {
  return is_enter_;
}
bool inputKey::IsExit() const {
  return is_exit_;
}
bool inputKey::IsRight() const {
  return is_locate_right_;
}
bool inputKey::IsLeft() const {
  return is_locate_left_;
}
bool inputKey::IsDown() const {
  return is_locate_down_;
}
bool inputKey::IsUp() const {
  return is_locate_up_;
}
bool inputKey::IsButtonEsc() const {
  return is_esc_button_;
}
bool inputKey::IsButtonAlt() const {
  return is_alt_button_;
}
bool inputKey::IsButtonCtrl() const {
  return is_ctrl_button_;
}
bool inputKey::IsButtonQ() const {
  return is_q_button_;
}
bool inputKey::IsButtonW() const {
  return is_w_button_;
}
bool inputKey::IsButtonE() const {
  return is_e_button_;
}
bool inputKey::IsButtonI() const {
  return is_i_button_;
}
bool inputKey::IsButtonO() const {
  return is_o_button_;
}
bool inputKey::IsButtonP() const {
  return is_p_button_;
}
bool inputKey::IsButtonA() const {
  return is_a_button_;
}
bool inputKey::IsButtonS() const {
  return is_s_button_;
}
bool inputKey::IsButtonD() const {
  return is_d_button_;
}
bool inputKey::IsButtonF() const {
  return is_f_button_;
}
bool inputKey::IsButtonM() const {
  return is_m_button_;
}
void inputKey::Update() {
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

  while (terminal_has_input()) {
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
}
