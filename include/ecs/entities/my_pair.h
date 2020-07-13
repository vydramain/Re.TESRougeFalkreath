//
// Created by vydra on 13.07.2020.
//

#ifndef RE_TESROUGEFALKREATH_MY_PAIR_H
#define RE_TESROUGEFALKREATH_MY_PAIR_H

template<typename T1, typename T2>
class my_pair {
private:
    T1 *first;
    T2 *second;

public:
    explicit my_pair(T1 *input_first = nullptr, T2 *input_second = nullptr) : first(input_first), second(input_second) {}

    my_pair(my_pair &input_pair) {
        first = new T1(input_pair.first);
        second = new T2(input_pair.second);
    }

    my_pair(my_pair &&input_pair) noexcept {
        first = input_pair.first;
        second = input_pair.second;
        input_pair.first = nullptr;
        input_pair.second = nullptr;
    }

    ~my_pair() {
        delete first;
        delete second;
    }

    my_pair &operator=(my_pair &&input_pair) {
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

#endif //RE_TESROUGEFALKREATH_MY_PAIR_H
