
#include <iostream>
#include "ecs/entities/my_pair.h"

int main() {
    int *n = new int(2);
    my_pair<char, int> p(new char('f'), n);
    std::cout << p.get_first() << ", " << *p.get_second() << std::endl;

    return 0;
}