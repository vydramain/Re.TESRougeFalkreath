//
// Created by vydra on 7/15/19.
//

#include "player.h"
#include "collisio.h"



void player::Move() {
  if (InputKey_.IsUp()) {
    //y_--;
    y_m--;
  }
  if (InputKey_.IsDown()) {
    //y_++;
    y_m++;
  }
  if (InputKey_.IsLeft()) {
    //x_--;
    x_m--;
  }
  if (InputKey_.IsRight()) {
    //x_++;
    x_m++;
  }
}

void player::getTerrain(unsigned &xm, unsigned &ym){
  xm=x_m;
  ym=y_m;
}
void player::getLocation(unsigned &x, unsigned &y){
  x=x_;
  y=y_;
}

void player::render() {
  /*if(x_m<30){
    x_= x_m;
  }
  if(y_m<20){
    y_= y_m;
  }
  if(x_m>){
    x_= x_m;
  }
  if(x_m>30){
    x_= x_m;
  }*/

  terminal_color(0xfffdff70);
  terminal_put_ext(x_, y_, 0 , 0,symbol); //, 0xaaFFAAff);

}