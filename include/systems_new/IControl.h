//
// Created by vydra on 7/30/20.
//

#pragma once

class IControl {
 private:
  const char* name;

 public:
  explicit IControl(const char* input_name = "IControl") : name(input_name) {}
  virtual ~IControl() = default;

  const char* get_name() {
    return name;
  }
  virtual void execute() = 0;
};
