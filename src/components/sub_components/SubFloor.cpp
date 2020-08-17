//
// Created by vydra on 8/14/20.
//

#include "components/sub_components/SubFloor.hpp"

SubFloor::SubFloor(bool input_floor) : AbsFloor(input_floor) {}
SubFloor::~SubFloor() = default;

void SubFloor::set_floor(bool input_floor) {
  is_floor = input_floor;
}

bool SubFloor::get_floor() const {
  return is_floor;
}
