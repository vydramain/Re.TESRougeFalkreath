//
// Created by vydra on 7/31/20.
//

#pragma once

#include <vector>

#include "systems/IControl.h"

class GCOControlSelectExit : public IControl {
 private:
  std::vector<ParameterQueryData *> *configuration_data = nullptr;

 public:
  explicit GCOControlSelectExit(std::vector<ParameterQueryData *> *input_configuration_data)
      : IControl("GCOControlSelectExit") {
    configuration_data = input_configuration_data;
  }
  ~GCOControlSelectExit() override = default;

  void execute() override {
    if (std::strcmp(configuration_data->at(0)->get_title()->data(), "Конфигурация графического режима:") != 0) {
      for (auto &i : *configuration_data) {
        if (std::strcmp(i->get_title()->data(), "Конфигурация графического режима:") == 0) {
          auto temp_data_pointer = configuration_data->at(0);
          configuration_data->at(0) = i;
          i = temp_data_pointer;
        }
      }
    }
  }
};
