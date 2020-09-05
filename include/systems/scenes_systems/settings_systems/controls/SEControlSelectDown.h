//
// Created by vydra on 7/31/20.
//

#include "entities/ParameterQueryData.hpp"
#include "systems/IControl.h"

class SEControlSelectDown : public IControl {
 private:
  GameSettingsData* global_settings_data;
  ParameterQueryData* settings_data;

 public:
  explicit SEControlSelectDown(ParameterQueryData* input_settings_data, GameSettingsData* input_global_settings_data)
      : IControl("SEControlSelectDown") {
    settings_data = input_settings_data;
    global_settings_data = input_global_settings_data;
  }
  ~SEControlSelectDown() override = default;

  void execute() override {
    if (settings_data->get_highlighted() < settings_data->get_count_choices()) {
      settings_data->set_highlighted(settings_data->get_highlighted() + 1);
      global_settings_data->set_rouge(false);
    }
  }
};
