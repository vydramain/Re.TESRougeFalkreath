//
// Created by vydra on 10.07.2020.
//

#ifndef RE_TESROUGEFALKREATH_GLOBAL_GAME_STATE_H
#define RE_TESROUGEFALKREATH_GLOBAL_GAME_STATE_H

#include <string>
#include <gsm/game_states/interface_game_state.h>

class global_game_state : public interface_game_state {
protected:
    bool is_closed_ = false;
    const char *state;
    unsigned state_size;

public:
    /*
     * Constructor
     */
    explicit global_game_state(const char *input_state = nullptr, unsigned input_state_size = 0) :
            state(input_state), state_size(input_state_size) {
    }

    /*
     * Copy constructor
     */
    global_game_state(global_game_state &input_state) {
        char *temp_state = new char[input_state.state_size];
        for (unsigned i = 0; i < input_state.state_size; i++){
            temp_state[i] = input_state.state[i];
        }
        state = temp_state;
        state_size = input_state.state_size;
        temp_state = nullptr;
    }

    /*
     * Move constructor
     */
    global_game_state(global_game_state &&input_state) noexcept {
        state = input_state.state;
        state_size = input_state.state_size;
        input_state.state = nullptr;
    }

    /*
     * Destructor
     */
    ~global_game_state() {
        delete state;
    }

    /*
     * Assigment
     */
    global_game_state &operator=(global_game_state &&input_state) noexcept {
        state = input_state.state;
        state_size = input_state.state_size;
        input_state.state = nullptr;
        return *this;
    }

    virtual void update() const = 0;
    const char *get_game_state() const;
    bool is_closed() const;
};

#endif //RE_TESROUGEFALKREATH_GLOBAL_GAME_STATE_H
