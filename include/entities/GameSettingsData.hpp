//
// Created by vydra on 9/5/20.
//

#pragma once

class GameSettingsData {
 private:
  bool rouge_set;

 public:
  explicit GameSettingsData();
  ~GameSettingsData();

  void set_rouge(bool input_set);
  bool get_rouge();
};
