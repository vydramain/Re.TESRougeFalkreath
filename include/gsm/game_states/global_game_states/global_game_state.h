//
// Created by vydra on 10.07.2020.
//

#ifndef RE_TESROUGEFALKREATH_GLOBAL_GAME_STATE_H
#define RE_TESROUGEFALKREATH_GLOBAL_GAME_STATE_H


class global_game_state : public interface_game_state {
private:
    char *state;

public:
    /*
     * Constructor
     */
    explicit global_game_state(char *input_state = nullptr) : state(input_state) {}

    /*
     * Copy constructor
     */
    global_game_state(global_game_state &input_state) {
        state = new char(input_state.get_game_state());
    }

    /*
     * Move constructor
     */
    global_game_state(global_game_state &&input_state) noexcept {
        state = new char(input_state.get_game_state());
        delete input_state.state;
        input_state.state = nullptr;
    }

    /*
     * Destructor
     */
    ~global_game_state() override {
        delete state;
    }

    /*
     * Assigment
     */
    global_game_state &operator= (global_game_state &&input_state) noexcept {
        state = new char(input_state.get_game_state());
        delete input_state.state;
        input_state.state = nullptr;
        return *this;
    }

    char get_game_state() {
        return *state;
    }

};

#endif //RE_TESROUGEFALKREATH_GLOBAL_GAME_STATE_H
