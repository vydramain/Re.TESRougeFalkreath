//
// Created by vydra on 16.07.2020.
//

#ifndef RE_TESROUGEFALKREATH_G_CREATURES_H
#define RE_TESROUGEFALKREATH_G_CREATURES_H

#include <vector>
#include "Creature.h"


class Creatures {
private:
    std::vector<Creature> vec_creatures;

public:
    explicit Creatures(unsigned input_count) {
        vec_creatures.reserve(input_count);
    }

    ~Creatures() {
        vec_creatures.clear();
    }

    void put_creature(Creature input_creature);
    Creature *get_creature(unsigned input_index);
    const Creature *get_creature(unsigned input_index) const;
    unsigned get_size() const;

};

#endif //RE_TESROUGEFALKREATH_G_CREATURES_H
