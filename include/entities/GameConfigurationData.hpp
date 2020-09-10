//
// Created by vydra on 9/5/20.
//

#pragma once

#include <string>

#include "components/sub_components/SubResolution.hpp"

class GameConfigurationData {
 private:
  bool rouge_set;
  bool sprite_set;
  SubResolution *resolution_set;

 public:
  explicit GameConfigurationData();
  ~GameConfigurationData();

  void set_rouge(bool input_set);
  void set_sprite(bool input_set);

  bool get_rouge() const;
  bool get_sprite() const;
  SubResolution *get_resolution() const;
};
