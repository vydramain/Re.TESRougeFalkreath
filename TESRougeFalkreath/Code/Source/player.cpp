//
// Created by vydra on 7/15/19.
//

#include "collisio.h"
#include "player.h"

void player::Render() {
    terminal_put(x_, y_, symbol);
}

void player::Move(collisio q, collisio w, collisio e, collisio r, collisio t, collisio y, collisio u, collisio i, collisio o) {
    if (InputKey_.IsUp() && (!q.isOutCollisio(x_,y_-1) && !w.isInCollisio(x_,y_-1) && !e.isInCollisio(x_,y_-1)&& !r.isInCollisio(x_,y_-1)&& !t.isInCollisio(x_,y_-1)&& !y.isInCollisio(x_,y_-1)&& !u.isInCollisio(x_,y_-1)&& !i.isInCollisio(x_,y_-1)&& !o.isInCollisio(x_,y_-1))) {
        y_--;
    }
    if (InputKey_.IsDown() && (!q.isOutCollisio(x_,y_+1) && !w.isInCollisio(x_,y_+1) && !e.isInCollisio(x_,y_+1)&& !r.isInCollisio(x_,y_+1)&& !t.isInCollisio(x_,y_+1)&& !y.isInCollisio(x_,y_+1)&& !u.isInCollisio(x_,y_+1)&& !i.isInCollisio(x_,y_+1)&& !o.isInCollisio(x_,y_+1))) {
        y_++;
    }
    if (InputKey_.IsLeft() && (!q.isOutCollisio(x_-1,y_) && !w.isInCollisio(x_-1,y_) && !e.isInCollisio(x_-1,y_)&& !r.isInCollisio(x_-1,y_)&& !t.isInCollisio(x_-1,y_)&& !y.isInCollisio(x_-1,y_)&& !u.isInCollisio(x_-1,y_)&& !i.isInCollisio(x_-1,y_)&& !o.isInCollisio(x_-1,y_))) {
        x_--;
    }
    if (InputKey_.IsRight() && (!q.isOutCollisio(x_+1,y_) && !w.isInCollisio(x_+1,y_) && !e.isInCollisio(x_+1,y_)&& !r.isInCollisio(x_+1,y_)&& !t.isInCollisio(x_+1,y_)&& !y.isInCollisio(x_+1,y_) && !u.isInCollisio(x_+1,y_)&& !i.isInCollisio(x_+1,y_)&& !o.isInCollisio(x_+1,y_))) {
        x_++;
    }
}


void player::Update(collisio q, collisio w, collisio e, collisio r, collisio t, collisio y,collisio u,collisio i,collisio o) {
    Move(q, w, e, r, t, y, u, i, o);
    Render();
}