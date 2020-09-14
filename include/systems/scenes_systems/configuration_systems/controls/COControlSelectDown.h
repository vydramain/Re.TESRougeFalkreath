//
// Created by vydra on 7/31/20.
//

#include "systems/IControl.h"
#include "systems/launcher_system/data/GameConfigurationData.hpp"
#include "systems/launcher_system/data/ParameterQueryData.hpp"

class COControlSelectDown : public IControl {
 private:
  ParameterQueryData* settings_data;

 public:
  explicit COControlSelectDown(ParameterQueryData *input_settings_data)
      : IControl("COControlSelectDown") {
    settings_data = input_settings_data;
  }
  ~COControlSelectDown() override = default;

  void execute() override {
    if (settings_data->get_highlighted() < settings_data->get_count_choices()) {
      settings_data->set_highlighted(settings_data->get_highlighted() + 1);
    }
  }
};
