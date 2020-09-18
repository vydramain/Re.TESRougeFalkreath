//
// Created by vydra on 8/8/20.
//

#pragma once

#include <string>

class Entity {
 private:
  unsigned id = 0;
  std::string* name;

 public:
  explicit Entity(const char* input_name);
  virtual ~Entity();

  std::string* get_name() const;
  void set_name(const char* input_name);
};
