//
// Created by vydra on 15.07.2020.
//

#ifndef RE_TESROUGEFALKREATH_CREATURE_H
#define RE_TESROUGEFALKREATH_CREATURE_H

class creature {
private:
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
    explicit creature(const unsigned input_current_x = 0, const unsigned input_current_y = 0) : current_x(
            input_current_x), current_y(input_current_y) {
        current_direction = DIRECTION_LEFT;
    }
    creature(const creature &input_creature) = default;
    creature(creature &&input_creature) noexcept  : current_x(input_creature.current_x),
                                                    current_y(input_creature.current_y),
                                                    current_direction(input_creature.current_direction){
        input_creature.current_x = 0;
        input_creature.current_y = 0;
    }
    ~creature() = default;

    creature &operator=(creature &&input_creature) noexcept {
        current_x = input_creature.current_x;
        current_y = input_creature.current_y;
        current_direction = input_creature.current_direction;
        input_creature.current_x = 0;
        input_creature.current_y = 0;
    }

    unsigned int getCurrentX() const {
        return current_x;
    }

    void setCurrentX(unsigned int currentX) {
        current_x = currentX;
    }

    unsigned int getCurrentY() const {
        return current_y;
    }

    void setCurrentY(unsigned int currentY) {
        current_y = currentY;
    }

    direction getCurrentDirection() const {
        return current_direction;
    }

    void setCurrentDirection(direction currentDirection) {
        current_direction = currentDirection;
    }

    void go_up();
    void go_down();
    void go_left();
    void go_right();

};

#endif //RE_TESROUGEFALKREATH_CREATURE_H
