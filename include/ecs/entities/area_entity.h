//
// Created by vydra on 15.07.2020.
//

#ifndef RE_TESROUGEFALKREATH_MAP_H
#define RE_TESROUGEFALKREATH_MAP_H


class g_area {
private:
    unsigned size_x;
    unsigned size_y;

    char **data;
public:
    explicit g_area(const unsigned input_size_x = 0, const unsigned input_size_y = 0, char **input_data = nullptr)
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

    g_area(g_area &input_area) {
        size_x = input_area.size_x;
        size_y = input_area.size_y;
        if (input_area.data != nullptr) {
            data = new char *[size_x];
            for (unsigned i = 0; i < size_x; i++) {
                data[i] = new char[size_y];
            }
            for (unsigned i = 0; i < size_x; i++) {
                for (unsigned j = 0; j < size_y; j++) {
                    data[i][j] = input_area.data[i][j];
                }
            }
        }
    }

    g_area(g_area &&input_area) noexcept : size_x(input_area.size_x), size_y(input_area.size_y), data(input_area.data) {
        input_area.data = nullptr;
    }

    ~g_area() {
        for (unsigned i = 0; i < size_x; i++) {
            delete data[i];
        }
        delete data;
    }

    g_area &operator=(const g_area &input_area) {
        size_x = input_area.size_x;
        size_y = input_area.size_y;
        if (input_area.data != nullptr) {
            data = new char *[size_x];
            for (unsigned i = 0; i < size_x; i++) {
                data[i] = new char[size_y];
            }
            for (unsigned i = 0; i < size_x; i++) {
                for (unsigned j = 0; j < size_y; j++) {
                    data[i][j] = input_area.data[i][j];
                }
            }
        }
        return *this;
    }

    g_area &operator=(g_area &&input_area) noexcept {
        size_x = input_area.size_x;
        size_y = input_area.size_y;
        data = input_area.data;
        input_area.data = nullptr;
        return *this;
    }

    unsigned get_size_x();
    unsigned get_size_y();
    char get_cell(unsigned input_x, unsigned input_y);

};


#endif //RE_TESROUGEFALKREATH_MAP_H