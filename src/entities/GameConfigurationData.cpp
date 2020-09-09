//
// Created by vydra on 9/5/20.
//

#include "entities/GameConfigurationData.hpp"

GameConfigurationData::GameConfigurationData() {
  rouge_set = true;
}

GameConfigurationData::~GameConfigurationData() = default;

void GameConfigurationData::set_rouge(bool input_set) {
  rouge_set = input_set;
}

bool GameConfigurationData::get_rouge() {
  return rouge_set;
}
