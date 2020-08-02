//
// Created by vydra on 7/30/20.
//

#ifndef INCLUDE_ECS_SYSTEMS_CONTROLS_SYSTEM_ICONTROL_H_
#define INCLUDE_ECS_SYSTEMS_CONTROLS_SYSTEM_ICONTROL_H_

#include <BearLibTerminal.h>

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

#endif  // INCLUDE_ECS_SYSTEMS_CONTROLS_SYSTEM_ICONTROL_H_
