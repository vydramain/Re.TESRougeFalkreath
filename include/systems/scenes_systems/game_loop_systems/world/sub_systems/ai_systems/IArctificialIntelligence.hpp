//
// Created by vydra on 9/17/20.
//

#pragma once

class IArtificialIntelligence {
 public:
  virtual void look_around() = 0;
  virtual void fight_player() = 0;
  virtual void pursue_player() = 0;
  virtual void walk() = 0;
};