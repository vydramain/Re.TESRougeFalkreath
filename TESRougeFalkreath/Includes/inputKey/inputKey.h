//
// Created by vydra on 7/15/19.
//

#ifndef TESROUGEFALKREATH_INPUTKEY_H
#define TESROUGEFALKREATH_INPUTKEY_H
#include <BearLibTerminal.h>



class inputKey {
    private:
        bool is_exit_= false;
        bool is_locate_right_= false;
        bool is_locate_left_= false;
        bool is_locate_up_= false;
        bool is_locate_down_= false;
        bool is_ctrl_button_= false;
        bool is_alt_button_= false;
        bool is_esc_button_= false;
        bool is_i_button_= false;
        bool is_e_button_= false;
        bool is_q_button_= false;
        bool is_w_button_= false;
        bool is_a_button_= false;
        bool is_s_button_= false;
        bool is_d_button_= false;
        bool is_f_button_= false;
        bool is_o_button_= false;
        bool is_p_button_= false;
        bool is_m_button_= false;

    public:
        bool IsExit() const{return is_exit_;}
        bool IsRight() const{return is_locate_right_;}
        bool IsLeft() const{return is_locate_left_;}
        bool IsDown() const{return is_locate_down_;}
        bool IsUp() const{return is_locate_up_;}
        bool IsButtonEsc() const{return is_esc_button_;}
        bool IsButtonAlt() const{return is_alt_button_;}
        bool IsButtonCtrl() const{return is_ctrl_button_;}
        bool IsButtonQ() const{return is_q_button_;}
        bool IsButtonW() const{return is_w_button_;}
        bool IsButtonE() const{return is_e_button_;}
        bool IsButtonI() const{return is_i_button_;}
        bool IsButtonO() const{return is_o_button_;}
        bool IsButtonP() const{return is_p_button_;}
        bool IsButtonA() const{return is_a_button_;}
        bool IsButtonS() const{return is_s_button_;}
        bool IsButtonD() const{return is_d_button_;}
        bool IsButtonF() const{return is_f_button_;}
        bool IsButtonM() const{return is_m_button_;}

        void Update() {
            is_exit_= false;
            is_locate_right_= false;
            is_locate_left_= false;
            is_locate_up_= false;
            is_locate_down_= false;
            is_ctrl_button_= false;
            is_alt_button_= false;
            is_esc_button_= false;
            is_i_button_= false;
            is_e_button_= false;
            is_q_button_= false;
            is_w_button_= false;
            is_a_button_= false;
            is_s_button_= false;
            is_d_button_= false;
            is_f_button_= false;
            is_o_button_= false;
            is_p_button_= false;
            is_m_button_= false;

            while (terminal_has_input()) {
                auto key= terminal_read();
                if (key== TK_CLOSE) {
                    is_exit_= true;
                }
                if (key== TK_UP){
                    is_locate_up_= true;
                }
                if (key== TK_DOWN){
                    is_locate_down_= true;
                }
                if (key== TK_LEFT){
                    is_locate_left_= true;
                }
                if (key== TK_RIGHT){
                    is_locate_right_= true;
                }
                if (key== TK_ESCAPE){
                    is_esc_button_= true;
                }
                if (key== TK_CONTROL){
                    is_ctrl_button_= true;
                }
                if (key== TK_ALT){
                    is_alt_button_= true;
                }
                if (key== TK_Q){
                    is_q_button_= true;
                }
                if (key== TK_W){
                    is_w_button_= true;
                }
                if (key== TK_E){
                    is_e_button_= true;
                }
                if (key== TK_I){
                    is_i_button_= true;
                }
                if (key== TK_O){
                    is_o_button_= true;
                }
                if (key== TK_P){
                    is_p_button_= true;
                }
                if (key== TK_A){
                    is_a_button_= true;
                }
                if (key== TK_S){
                    is_s_button_= true;
                }
                if (key== TK_D){
                    is_d_button_= true;
                }
                if (key== TK_F){
                    is_f_button_= true;
                }
                if (key== TK_M){
                    is_m_button_= true;
                }
            }
        }
};


#endif //TESROUGEFALKREATH_INPUTKEY_H
