//
// Created by vydra on 7/15/19.
//

#include "collisio.h"
#include "player.h"

void player::Render() {
    terminal_put(x_, y_, symbol);
}

void player::Move() {
    if (InputKey_.IsUp()) {
        y_--;
    }
    if (InputKey_.IsDown()) {
        y_++;
    }
    if (InputKey_.IsLeft()) {
        x_--;
    }
    if (InputKey_.IsRight()) {
        x_++;
    }
}

void player::Update() {
    Move();
    Render();
}