//
// Created by vydra on 9/5/20.
//

#pragma once

#include <string>

#include "components/sub_components/SubResolution.hpp"

class GameConfigurationData {
 private:
  bool changes;

  bool rouge_set;
  bool sprite_set;
  SubResolution *resolution_set;

 public:
  explicit GameConfigurationData();
  ~GameConfigurationData();

  void set_rouge(bool input_set);
  void set_sprite(bool input_set);
  void set_resolution_1280x720();
  void set_resolution_1920x1080();

  bool has_changes();
  bool get_rouge() const;
  bool get_sprite() const;
  const SubResolution *get_resolution() const;
};
