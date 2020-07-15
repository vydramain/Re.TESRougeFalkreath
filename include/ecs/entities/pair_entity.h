//
// Created by vydra on 13.07.2020.
//

#ifndef RE_TESROUGEFALKREATH_PAIR_ENTITY_H
#define RE_TESROUGEFALKREATH_PAIR_ENTITY_H


template<typename T1, typename T2>
class pair_entity {
private:
    T1 *first;
    T2 *second;

public:
    explicit pair_entity(T1 *input_first = nullptr, T2 *input_second = nullptr) : first(input_first), second(input_second) {}

    pair_entity(pair_entity &input_pair) {
        first = new T1(input_pair.first);
        second = new T2(input_pair.second);
    }

    pair_entity(pair_entity &&input_pair) noexcept {
        first = input_pair.first;
        second = input_pair.second;
        input_pair.first = nullptr;
        input_pair.second = nullptr;
    }

    ~pair_entity() {
        delete first;
        delete second;
    }

    pair_entity &operator=(pair_entity &&input_pair) {
        first = input_pair.first;
        second = input_pair.second;
        input_pair.first = nullptr;
        input_pair.second = nullptr;
    }

    T1* get_first() {
        return first;
    }

    T2* get_second() {
        return second;
    }

};


#endif //RE_TESROUGEFALKREATH_PAIR_ENTITY_H
