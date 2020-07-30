//
// Created by vydra on 15.07.2020.
//

#ifndef RE_TESROUGEFALKREATH_MAP_H
#define RE_TESROUGEFALKREATH_MAP_H


class Map {
private:
    unsigned size_x;
    unsigned size_y;

    char **data;
public:
    explicit Map(const unsigned input_size_x = 0, const unsigned input_size_y = 0, char **input_data = nullptr)
            : size_x(input_size_x), size_y(input_size_y) {
        if (input_data != nullptr) {
            data = new char *[size_x];
            for (unsigned i = 0; i < size_x; i++) {
                data[i] = new char[size_y];
            }
            for (unsigned i = 0; i < size_x; i++) {
                for (unsigned j = 0; j < size_y; j++) {
                    data[i][j] = input_data[i][j];
                }
            }
        }
    }

    ~Map() {
        for (unsigned i = 0; i < size_x; i++) {
            delete data[i];
        }
        delete data;
    }

    unsigned get_size_x();
    unsigned get_size_y();
    char get_cell(unsigned input_x, unsigned input_y);

};


#endif //RE_TESROUGEFALKREATH_MAP_H
