//
// Created by vydra on 16.07.2020.
//

#ifndef RE_TESROUGEFALKREATH_CREATURES_H
#define RE_TESROUGEFALKREATH_CREATURES_H

#include <vector>
#include "creature.h"


class creatures {
private:
    std::vector<creature> vec_creatures;

public:
    explicit creatures(unsigned input_count) {
        vec_creatures.reserve(input_count);
    }
    creatures(creatures &input_creatures) {
        std::vector<creature>::iterator it;
        for(it = input_creatures.vec_creatures.begin(); it < input_creatures.vec_creatures.end(); it++) {
            vec_creatures.push_back(*it);
        }
    }
    creatures(creatures &&input_creatures) noexcept {
        std::vector<creature>::iterator it;
        for(it = input_creatures.vec_creatures.begin(); it < input_creatures.vec_creatures.end(); it++) {
            vec_creatures.push_back(*it);
        }
        input_creatures.vec_creatures.clear();
    }
    ~creatures() {
        vec_creatures.clear();
    }

    creatures &operator=(creatures &input_creatures) {
        std::vector<creature>::iterator it;
        for(it = input_creatures.vec_creatures.begin(); it < input_creatures.vec_creatures.end(); it++) {
            vec_creatures.push_back(*it);
        }
        return *this;
    }

    creatures &operator=(creatures &&input_creatures) noexcept {
        std::vector<creature>::iterator it;
        for(it = input_creatures.vec_creatures.begin(); it < input_creatures.vec_creatures.end(); it++) {
            vec_creatures.push_back(*it);
        }
        input_creatures.vec_creatures.clear();
        return *this;
    }

    void put_creature(creature input_creature);
    creature *get_creature(unsigned input_index);
//    ??? get_list_creatures();
};

#endif //RE_TESROUGEFALKREATH_CREATURES_H
