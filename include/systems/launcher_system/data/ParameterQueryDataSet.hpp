//
// Created by vydra on 9/18/20.
//

#pragma once

#include <cstring>
#include <string>

#include "systems/launcher_system/data/ParameterQueryData.hpp"

class ParameterQueryDataSet {
 private:
  std::vector<ParameterQueryData*> set;

 public:
  explicit ParameterQueryDataSet();
  ~ParameterQueryDataSet();

  ParameterQueryData* get_data(unsigned input_index) const;
  ParameterQueryData* get_data(std::string* input_name) const;

  void insert_data(ParameterQueryData* input_data);
};
