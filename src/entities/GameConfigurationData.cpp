//
// Created by vydra on 9/5/20.
//

#include "entities/GameConfigurationData.hpp"

GameConfigurationData::GameConfigurationData() {
  changes = false;
  rouge_set = false;
  sprite_set = false;
  resolution_set = new SubResolution();
}

GameConfigurationData::~GameConfigurationData() {
  delete resolution_set;
}

void GameConfigurationData::set_rouge(bool input_set) {
  changes = true;
  rouge_set = input_set;
}

void GameConfigurationData::set_sprite(bool input_set) {
  changes = true;
  sprite_set = input_set;
}

void GameConfigurationData::set_resolution_1280x720() {
  changes = true;
  resolution_set->set_1280x720();
}

void GameConfigurationData::set_resolution_1920x1080() {
  changes = true;
  resolution_set->set_1920x1080();
}

bool GameConfigurationData::has_changes() {
  if (changes) {
    changes = false;
    return true;
  }
  return false;
}

bool GameConfigurationData::get_rouge() const {
  return rouge_set;
}

bool GameConfigurationData::get_sprite() const {
  return sprite_set;
}

const SubResolution *GameConfigurationData::get_resolution() const {
  return resolution_set;
}
