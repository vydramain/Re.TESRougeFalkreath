//
// Created by vydra on 9/5/20.
//

#pragma once

class GameConfigurationData {
 private:
  bool rouge_set;

 public:
  explicit GameConfigurationData();
  ~GameConfigurationData();

  void set_rouge(bool input_set);
  bool get_rouge();
};
