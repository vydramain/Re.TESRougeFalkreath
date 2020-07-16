//
// Created by vydra on 16.07.2020.
//

#ifndef RE_TESROUGEFALKREATH_G_CREATURES_H
#define RE_TESROUGEFALKREATH_G_CREATURES_H

#include <vector>
#include "creature_entity.h"


class creatures_entity {
private:
    std::vector<creature_entity> vec_creatures;

public:
    explicit creatures_entity(unsigned input_count) {
        vec_creatures.reserve(input_count);
    }
    creatures_entity(creatures_entity &input_creatures) {
        std::vector<creature_entity>::iterator it;
        for(it = input_creatures.vec_creatures.begin(); it < input_creatures.vec_creatures.end(); it++) {
            vec_creatures.push_back(*it);
        }
    }
    creatures_entity(creatures_entity &&input_creatures) noexcept {
        std::vector<creature_entity>::iterator it;
        for(it = input_creatures.vec_creatures.begin(); it < input_creatures.vec_creatures.end(); it++) {
            vec_creatures.push_back(*it);
        }
        input_creatures.vec_creatures.clear();
    }
    ~creatures_entity() {
        vec_creatures.clear();
    }

    creatures_entity &operator=(creatures_entity &input_creatures) {
        std::vector<creature_entity>::iterator it;
        for(it = input_creatures.vec_creatures.begin(); it < input_creatures.vec_creatures.end(); it++) {
            vec_creatures.push_back(*it);
        }
        return *this;
    }

    creatures_entity &operator=(creatures_entity &&input_creatures) noexcept {
        std::vector<creature_entity>::iterator it;
        for(it = input_creatures.vec_creatures.begin(); it < input_creatures.vec_creatures.end(); it++) {
            vec_creatures.push_back(*it);
        }
        input_creatures.vec_creatures.clear();
        return *this;
    }

    void put_creature(creature_entity input_creature);
    creature_entity *get_creature(unsigned input_index);
//    ??? get_list_creatures();
};

#endif //RE_TESROUGEFALKREATH_G_CREATURES_H
