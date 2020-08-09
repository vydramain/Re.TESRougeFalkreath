//
// Created by vydra on 8/8/20.
//

#pragma once

class Entity {
 private:
  unsigned id = 0;
  const char* name;

 public:
  explicit Entity(const char* input_name);
  virtual ~Entity() = default;

  const char* get_name() const;
  void set_name(const char* input_name);
};
