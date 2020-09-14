//
// Created by vydra on 7/31/20.
//

#include <vector>

#include "entities/data_entities/GameConfigurationData.hpp"
#include "entities/data_entities/ParameterQueryData.hpp"
#include "systems/IControl.h"

class GCOControlSelectDown : public IControl {
 private:
  std::vector<ParameterQueryData *> *configuration_data;

 public:
  explicit GCOControlSelectDown(std::vector<ParameterQueryData *> *input_configuration_data)
      : IControl("CEControlSelectDown") {
    configuration_data = input_configuration_data;
  }
  ~GCOControlSelectDown() override = default;

  void execute() override {
    if (configuration_data->at(0)->get_highlighted() < configuration_data->at(0)->get_count_choices()) {
      configuration_data->at(0)->set_highlighted(configuration_data->at(0)->get_highlighted() + 1);
    }
  }
};
