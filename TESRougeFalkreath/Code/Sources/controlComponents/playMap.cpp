#include "controlComponents/playMap.h"

playMap::playMap() {
  mapName_ = 0;
  ph = nullptr;
  pb = nullptr;
  countX_ = 0;
  countY_ = 0;
  errorcode = 0;
}

bool playMap::newKnot1() {
  if (errorcode == 0) {
    if (ph != nullptr) {
      pb = ph;
      while (pb->next1 != nullptr) {
        pb = pb->next1;
      }
      pknot p = new knot();
      p->next1 = nullptr;
      p->next2 = nullptr;
      pb->next1 = p;
    } else {
      pknot p = new knot();
      p->next1 = nullptr;
      p->next2 = nullptr;
      ph = p;
    }
    return false;
  } else {
    return true;
  }
}

bool playMap::newKnot2(unsigned Y) {
  if (errorcode == 0 && Y < countY_) {
    if (ph != nullptr) {
      pb = ph;
      for (unsigned i(0); i < Y; i++) {
        pb = pb->next1;
      }
      while (pb->next2 != nullptr) {
        pb = pb->next2;
      }
      pknot p = new knot();
      p->next1 = nullptr;
      p->next2 = nullptr;
      pb->next2 = p;
    } else {
      pknot p = new knot();
      p->next1 = nullptr;
      p->next2 = nullptr;
      ph = p;
    }
    return 0;
  } else {
    return 1;
  }
}

playMap::playMap(unsigned Name, unsigned X, unsigned Y) {
  mapName_ = Name;
  countX_ = X;
  countY_ = Y;
  ph = nullptr;
  for (unsigned i(0); i < countY_; i++) {
    if (ph != nullptr) {
      pb = ph;
      while (pb->next1 != nullptr) {
        pb = pb->next1;
      }
      pknot p = new knot();
      p->next1 = nullptr;
      p->next2 = nullptr;
      pb->next1 = p;
    } else {
      pknot p = new knot();
      p->next1 = nullptr;
      p->next2 = nullptr;
      ph = p;
    }
  }
  for (unsigned i(0); i < countY_; i++) {
    for (unsigned ii(0); ii < countX_; ii++) {
      if (ph != nullptr) {
        pb = ph;
        for (unsigned I(1); I < i; I++) {
          pb = pb->next1;
        }
        while (pb->next2 != nullptr) {
          pb = pb->next2;
        }
        pknot p = new knot();
        p->next1 = nullptr;
        p->next2 = nullptr;
        pb->next2 = p;
      } else {
        pknot p = new knot();
        p->next1 = nullptr;
        p->next2 = nullptr;
        ph = p;
      }
    }
  }
}

playMap::~playMap() {
  for (unsigned i(0); i < countY_; i++) {
    for (unsigned ii(0); ii < countX_; ii++) {
      pb = ph;
      while (pb->next1 != nullptr) {
        pb = pb->next1;
      }
      while (pb->next2 != nullptr) {
        pb = pb->next2;
      }
      pb = nullptr;
    }
  }
  ph = nullptr;
}

bool playMap::changeKnot(unsigned X, unsigned Y, char lay0, char lay1, char lay2, char lay3) {
  if (X <= countX_ && Y <= countY_) {
    pb = ph;
    for (unsigned i(1); i < Y; i++) {
      pb = pb->next1;
    }
    for (unsigned i(1); i < X; i++) {
      pb = pb->next2;
    }
    pb->layer0 = lay0;
    pb->layer1 = lay1;
    pb->layer2 = lay2;
    pb->layer3 = lay3;
    return 0;
  } else {
    return 1;
  }
}

bool playMap::changeKnot0(unsigned X, unsigned Y, char lay) {
  if (X <= countX_ && Y <= countY_) {
    pb = ph;
    for (unsigned i(0); i < Y; i++) {
      pb = pb->next1;
    }
    for (unsigned i(0); i < X; i++) {
      pb = pb->next2;
    }
    pb->layer0 = lay;
    return 0;
  } else {
    return 1;
  }
}

bool playMap::changeKnot1(unsigned X, unsigned Y, char lay) {
  if (X <= countX_ && Y <= countY_) {
    pb = ph;
    for (unsigned i(0); i < Y; i++) {
      pb = pb->next1;
    }
    for (unsigned i(0); i < X; i++) {
      pb = pb->next2;
    }
    pb->layer1 = lay;
    return 0;
  } else {
    return 1;
  }
}

bool playMap::changeKnot2(unsigned X, unsigned Y, char lay) {
  if (X <= countX_ && Y <= countY_) {
    pb = ph;
    for (unsigned i(0); i < Y; i++) {
      pb = pb->next1;
    }
    for (unsigned i(0); i < X; i++) {
      pb = pb->next2;
    }
    pb->layer2 = lay;
    return 0;
  } else {
    return 1;
  }
}

bool playMap::changeKnot3(unsigned X, unsigned Y, char lay) {
  if (X <= countX_ && Y <= countY_) {
    pb = ph;
    for (unsigned i(0); i < Y; i++) {
      pb = pb->next1;
    }
    for (unsigned i(0); i < X; i++) {
      pb = pb->next2;
    }
    pb->layer3 = lay;
    return 0;
  } else {
    return 1;
  }
}

bool playMap::pullKnot(unsigned X, unsigned Y, char &lay0, char &lay1, char &lay2, char &lay3) {
  if (X <= countX_ && Y <= countY_) {
    pb = ph;
    for (unsigned i(0); i < Y; i++) {
      pb = pb->next1;
    }
    for (unsigned i(0); i < X; i++) {
      pb = pb->next2;
    }
    lay0 = pb->layer0;
    lay1 = pb->layer1;
    lay2 = pb->layer2;
    lay3 = pb->layer3;
    return 0;
  } else {
    return 1;
  }
}

bool playMap::pullKnot0(unsigned X, unsigned Y, char &lay) {
  if (X <= countX_ && Y <= countY_) {
    pb = ph;
    for (unsigned i(0); i < Y; i++) {
      pb = pb->next1;
    }
    for (unsigned i(0); i < X; i++) {
      pb = pb->next2;
    }
    lay = pb->layer0;
    return 0;
  } else {
    return 1;
  }
}

bool playMap::pullKnot1(unsigned X, unsigned Y, char &lay) {
  if (X <= countX_ && Y <= countY_) {
    pb = ph;
    for (unsigned i(0); i < Y; i++) {
      pb = pb->next1;
    }
    for (unsigned i(0); i < X; i++) {
      pb = pb->next2;
    }
    lay = pb->layer1;
    return 0;
  } else {
    return 1;
  }
}

bool playMap::pullKnot2(unsigned X, unsigned Y, char &lay) {
  if (X <= countX_ && Y <= countY_) {
    pb = ph;
    for (unsigned i(0); i < Y; i++) {
      pb = pb->next1;
    }
    for (unsigned i(0); i < X; i++) {
      pb = pb->next2;
    }
    lay = pb->layer2;
    return 0;
  } else {
    return 1;
  }
}

bool playMap::pullKnot3(unsigned X, unsigned Y, char &lay) {
  if (X <= countX_ && Y <= countY_) {
    pb = ph;
    for (unsigned i(0); i < Y; i++) {
      pb = pb->next1;
    }
    for (unsigned i(0); i < X; i++) {
      pb = pb->next2;
    }
    lay = pb->layer3;
    return 0;
  } else {
    return 1;
  }
}

void playMap::viewSize(unsigned &X, unsigned &Y) {
  X = countX_;
  Y = countY_;
}