//
// Created by vydra on 7/17/19.
//

#include "collisio.h"

bool collisio::isInCollisio(unsigned x, unsigned y) {
  if ((x > x_ && x < x_s) && (y > y_ && y < y_s)) {
    return true;
  } else {
    return false;
  }
}

bool collisio::isOutCollisio(unsigned x, unsigned y) {
  if ((x > x_ && x < x_s) && (y > y_ && y < y_s)) {
    return false;
  } else {
    return true;
  }
}