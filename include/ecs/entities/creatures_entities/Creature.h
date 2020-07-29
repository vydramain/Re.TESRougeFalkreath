//
// Created by vydra on 15.07.2020.
//

#ifndef RE_TESROUGEFALKREATH_CREATURE_H
#define RE_TESROUGEFALKREATH_CREATURE_H

class Creature {
private:
    const char *name;
    unsigned current_x;
    unsigned current_y;

    enum direction {
        DIRECTION_UP,
        DIRECTION_DOWN,
        DIRECTION_RIGHT,
        DIRECTION_LEFT,
    };

    direction current_direction;

public:
    explicit Creature(const char *input_name, const unsigned input_current_x = 0, const unsigned input_current_y = 0) :
            name(input_name), current_x(input_current_x), current_y(input_current_y) {
        current_direction = DIRECTION_LEFT;
    }

    const char *get_name() const;
    unsigned get_current_x() const;
    unsigned get_current_y() const;
    unsigned get_current_direction() const;

    void set_name(char *input_name);
    void set_current_x(unsigned int input_x);
    void set_current_y(unsigned int input_y);
    void set_current_direction(direction input_direction);

    void go_up();
    void go_down();
    void go_left();
    void go_right();

};

#endif //RE_TESROUGEFALKREATH_CREATURE_H
