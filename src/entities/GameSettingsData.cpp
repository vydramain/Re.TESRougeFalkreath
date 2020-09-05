//
// Created by vydra on 9/5/20.
//

#include "entities/GameSettingsData.hpp"

GameSettingsData::GameSettingsData() {
  rouge_set = true;
}

GameSettingsData::~GameSettingsData() = default;

void GameSettingsData::set_rouge(bool input_set) {
  rouge_set = input_set;
}

bool GameSettingsData::get_rouge() {
  return rouge_set;
}
