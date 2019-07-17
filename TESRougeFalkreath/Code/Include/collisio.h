//
// Created by vydra on 7/17/19.
//

#ifndef TESROUGEFALKREATH_COLLISIO_H
#define TESROUGEFALKREATH_COLLISIO_H



class collisio {
private:
    unsigned x_, y_;
    unsigned x_s, y_s;

public:
    collisio(unsigned a, unsigned b, unsigned c, unsigned d) : x_(a), y_(b), x_s(c), y_s(d) {}


    bool isInCollisio(unsigned x, unsigned y); // нельзя внутрь
    bool isOutCollisio(unsigned x, unsigned y); // нельзя внаружу^^
};



#endif //TESROUGEFALKREATH_COLLISIO_H
