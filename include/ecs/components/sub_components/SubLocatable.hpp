//
// Created by vydra on 8/7/20.
//

#pragma once

#include "ecs/components/abs_components/AbsLocatable.hpp"

class SubLocatable : public AbsLocatable {
public:
    explicit SubLocatable(unsigned input_x, unsigned input_y);
    ~SubLocatable();

    unsigned get_current_x() const;
    unsigned get_current_y() const;

    void set_current_x(unsigned int input_x);
    void set_current_y(unsigned int input_y);
};