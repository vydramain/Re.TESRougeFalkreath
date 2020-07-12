//
// Created by vydra on 12.07.2020.
//

#ifndef RE_TESROUGEFALKREATH_INTERFACE_RENDER_H
#define RE_TESROUGEFALKREATH_INTERFACE_RENDER_H

class interface_render {
public:
    interface_render() = default;
    virtual ~interface_render() = default;
    virtual void render() = 0;
};

#endif //RE_TESROUGEFALKREATH_INTERFACE_RENDER_H
