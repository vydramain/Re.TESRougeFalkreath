//
// Created by vydra on 9/18/20.
//

#include <cstring>
#include <string>

#include "systems/launcher_system/data/ParameterQueryDataSet.hpp"

ParameterQueryDataSet::ParameterQueryDataSet() = default;

ParameterQueryDataSet::~ParameterQueryDataSet() {
  set.clear();
}

ParameterQueryData* ParameterQueryDataSet::get_data(unsigned int input_index) const {
  return set[input_index];
}

ParameterQueryData* ParameterQueryDataSet::get_data(std::string* input_name) const {
  for (ParameterQueryData* data : set) {
    if (std::strcmp(input_name->data(), data->get_name()->data()) == 0) {
      return data;
    }
  }
  return nullptr;
}

void ParameterQueryDataSet::insert_data(ParameterQueryData* input_data) {
  set.push_back(input_data);
}
