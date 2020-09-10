//
// Created by vydra on 9/5/20.
//

#include "entities/GameConfigurationData.hpp"

GameConfigurationData::GameConfigurationData() {
  rouge_set = false;
  sprite_set = false;
  resolution_set = new SubResolution();
}

GameConfigurationData::~GameConfigurationData() = default;

void GameConfigurationData::set_rouge(bool input_set) {
  rouge_set = input_set;
}

void GameConfigurationData::set_sprite(bool input_set) {
  sprite_set = input_set;
}

bool GameConfigurationData::get_rouge() const {
  return rouge_set;
}

bool GameConfigurationData::get_sprite() const {
  return sprite_set;
}

SubResolution *GameConfigurationData::get_resolution() const {
  return resolution_set;
}
