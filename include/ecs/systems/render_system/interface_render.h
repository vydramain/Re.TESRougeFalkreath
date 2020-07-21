//
// Created by vydra on 12.07.2020.
//

#ifndef RE_TESROUGEFALKREATH_INTERFACE_RENDER_H
#define RE_TESROUGEFALKREATH_INTERFACE_RENDER_H

#include "BearLibTerminal.h"

class interface_render {
public:
    interface_render() = default;
    virtual ~interface_render() = default;

    virtual void clear_all() = 0;
    virtual void clear_area(unsigned in_x, unsigned in_y, unsigned out_x, unsigned out_y) = 0;
    virtual void render() = 0;
};

#endif //RE_TESROUGEFALKREATH_INTERFACE_RENDER_H
