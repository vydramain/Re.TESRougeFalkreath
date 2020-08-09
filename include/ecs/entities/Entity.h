//
// Created by vydra on 8/8/20.
//

#pragma once

class Entity {
 private:
  int id = 0;
  const char* name;

 public:
  explicit Entity(const char* input_name);
  ~Entity() = default;

  const char* get_name() const;
  void set_name(const char* input_name);
};
