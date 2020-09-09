//
// Created by vydra on 7/31/20.
//

#include "entities/GameConfigurationData.hpp"
#include "entities/ParameterQueryData.hpp"
#include "systems/IControl.h"

class GPCOControlSelectDown : public IControl {
 private:
  ParameterQueryData* settings_data;

 public:
  explicit GPCOControlSelectDown(ParameterQueryData *input_settings_data)
      : IControl("GPCOControlSelectDown") {
    settings_data = input_settings_data;
  }
  ~GPCOControlSelectDown() override = default;

  void execute() override {
    if (settings_data->get_highlighted() < settings_data->get_count_choices()) {
      settings_data->set_highlighted(settings_data->get_highlighted() + 1);
    }
  }
};
