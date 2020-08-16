//
// Created by vydra on 8/12/20.
//

#pragma once

class IRender {
 public:
  IRender() = default;;
  virtual ~IRender() = default;;

  virtual void render() = 0;
};
