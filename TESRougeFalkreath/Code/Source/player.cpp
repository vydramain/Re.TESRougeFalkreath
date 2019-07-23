//
// Created by vydra on 7/15/19.
//

#include "player.h"
#include "collisio.h"

void player::Render() {
  terminal_put(x_, y_, symbol);
}

void player::Move() {
  if (InputKey_.IsUp()) {
    y_--;
    y_m--;
  }
  if (InputKey_.IsDown()) {
    y_++;
    y_m++;
  }
  if (InputKey_.IsLeft()) {
    x_--;
    x_m--;_
  }
  if (InputKey_.IsRight()) {
    x_++;
    x_m++;
  }
}

void player::Update() {
  Move();
  Render();
}