//
// Created by vydra on 8/10/20.
//

#include "core/systems/location_system/sub_systems/entities_system/LocationsEntitiesSystem.h"

LocationsEntitiesSystem::LocationsEntitiesSystem() = default;

LocationsEntitiesSystem::LocationsEntitiesSystem(const LocationsEntitiesSystem& input_data)
    : SentientsSystem(), MagwehrsSystem(), ItemsSystem() {
  for (const auto sentient : input_data.sentients) {
    entities.push_back(*sentient);
    sentients.push_back(sentient);
  }
  for (const auto magwehr : input_data.magwehrs) {
    entities.push_back(*magwehr);
    magwehrs.push_back(magwehr);
  }
  for (const auto item : input_data.items) {
    entities.push_back(*item);
    items.push_back(item);
  }
  for (const auto ambient : input_data.ambients) {
    entities.push_back(*ambient);
    ambients.push_back(ambient);
  }
}

LocationsEntitiesSystem::~LocationsEntitiesSystem() {
  entities.clear();
}

void LocationsEntitiesSystem::put_ambient(Ambient* input_ambient) {
  entities.push_back(*input_ambient);
  AmbientsSystem::put_ambient(input_ambient);
}

void LocationsEntitiesSystem::put_item(Item* input_entity) {
  entities.push_back(*input_entity);
  ItemsSystem::put_item(input_entity);
}

void LocationsEntitiesSystem::put_magwehr(Magwehr* input_entity) {
  entities.push_back(*input_entity);
  MagwehrsSystem::put_magwehr(input_entity);
}

void LocationsEntitiesSystem::put_player(Sentient* input_entity) {
  entities.push_back(*input_entity);
  SentientsSystem::put_player(input_entity);
}

void LocationsEntitiesSystem::put_sentient(Sentient* input_entity) {
  entities.push_back(*input_entity);
  SentientsSystem::put_sentient(input_entity);
}

Ambient* LocationsEntitiesSystem::remove_ambient(unsigned int input_index) {
  return AmbientsSystem::remove_ambient(input_index);
}

Item* LocationsEntitiesSystem::remove_item(unsigned int input_index) {
  return ItemsSystem::remove_item(input_index);
}

Magwehr* LocationsEntitiesSystem::remove_magwehr(unsigned int input_index) {
  return MagwehrsSystem::remove_magwehr(input_index);
}

Sentient* LocationsEntitiesSystem::remove_player() {
  return SentientsSystem::remove_sentient(0);
}

Sentient* LocationsEntitiesSystem::remove_sentient(unsigned int input_index) {
  return SentientsSystem::remove_sentient(input_index);
}

LocationsEntity* LocationsEntitiesSystem::get_entity(unsigned int input_index) {
  return &entities[input_index];
}

const LocationsEntity* LocationsEntitiesSystem::get_entity(unsigned int input_index) const {
  const LocationsEntity* pointer = entities.data();
  return &pointer[input_index];
}
