//
// Created by vydra on 9/3/20.
//

#pragma once

#include <string>

class ISubject {
 public:
  virtual ~ISubject() = default;
  virtual void update(std::string input) = 0;
};