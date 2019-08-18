//
// Created by vydra on 7/15/19.
//

#ifndef TESROUGEFALKREATH_CODE_HEADERS_INGAMEPARTS_CONTROLCOMPONENTS_INPUTKEY_H_
#define TESROUGEFALKREATH_CODE_HEADERS_INGAMEPARTS_CONTROLCOMPONENTS_INPUTKEY_H_

#include <BearLibTerminal.h>

class inputKey {
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
  explicit inputKey() {}

  // inputKey(const inputKey& old);
  ~inputKey() {}
  // inputKey & operator= (const inputKey& old);

  bool IsEnter() const;
  bool IsExit() const;
  bool IsRight() const;
  bool IsLeft() const;
  bool IsDown() const;
  bool IsUp() const;
  bool IsButtonEsc() const;
  bool IsButtonAlt() const;
  bool IsButtonCtrl() const;
  bool IsButtonQ() const;
  bool IsButtonW() const;
  bool IsButtonE() const;
  bool IsButtonI() const;
  bool IsButtonO() const;
  bool IsButtonP() const;
  bool IsButtonA() const;
  bool IsButtonS() const;
  bool IsButtonD() const;
  bool IsButtonF() const;
  bool IsButtonM() const;

  void Update();
};

#endif  // TESROUGEFALKREATH_CODE_HEADERS_INGAMEPARTS_CONTROLCOMPONENTS_INPUTKEY_H_
