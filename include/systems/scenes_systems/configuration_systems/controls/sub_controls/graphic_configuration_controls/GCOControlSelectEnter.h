//
// Created by vydra on 7/31/20.
//

#pragma once

#include <vector>

#include "entities/data_entities/GameConfigurationData.hpp"
#include "entities/data_entities/ParameterQueryData.hpp"
#include "systems/IControl.h"

class GCOControlSelectEnter : public IControl {
  std::vector<ParameterQueryData *> *configuration_data = nullptr;
  GameConfigurationData *global_configuration_data = nullptr;

 public:
  explicit GCOControlSelectEnter(std::vector<ParameterQueryData *> *input_configuration_data,
                                 GameConfigurationData *input_global_configuration_data)
      : IControl("GCOControlSelectEnter") {
    configuration_data = input_configuration_data;
    global_configuration_data = input_global_configuration_data;
  }
  ~GCOControlSelectEnter() override = default;

  void execute() override {
    if (std::strcmp(configuration_data->at(0)->get_title()->data(), "Выберете новое разрешение:") == 0) {
      if (configuration_data->at(0)->get_highlighted() == 1) {
        global_configuration_data->set_resolution_1920x1080();
      }
      if (configuration_data->at(0)->get_highlighted() == 2) {
        global_configuration_data->set_resolution_1280x720();
      }
    }
    if (std::strcmp(configuration_data->at(0)->get_title()->data(), "Выберете режим отоборажения объектов:") == 0) {
      if (configuration_data->at(0)->get_highlighted() == 1) {
        global_configuration_data->set_sprite(false);
      }
      if (configuration_data->at(0)->get_highlighted() == 2) {
        global_configuration_data->set_sprite(true);
      }
    }
    if (std::strcmp(configuration_data->at(0)->get_title()->data(), "Конфигурация графического режима:") == 0) {
      ParameterQueryData *temp_data_pointer = nullptr;
      if (configuration_data->at(0)->get_highlighted() == 1) {
        temp_data_pointer = configuration_data->at(0);
        configuration_data->at(0) = configuration_data->at(1);
        configuration_data->at(1) = temp_data_pointer;
      }
      if (configuration_data->at(0)->get_highlighted() == 2) {
        temp_data_pointer = configuration_data->at(0);
        configuration_data->at(0) = configuration_data->at(2);
        configuration_data->at(2) = temp_data_pointer;
      }
    }
  }
};
