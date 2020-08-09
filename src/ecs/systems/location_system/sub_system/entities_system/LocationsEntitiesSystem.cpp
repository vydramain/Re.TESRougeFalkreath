//
// Created by vydra on 8/10/20.
//

#include "ecs/systems/location_system/sub_systems/entities_system/LocationsEntitiesSystem.h"

LocationsEntitiesSystem::LocationsEntitiesSystem() = default;

LocationsEntitiesSystem::~LocationsEntitiesSystem() {
  entities.clear();
}

void LocationsEntitiesSystem::put_item(Item* input_entity) {
  ItemsSystem::put_item(input_entity);
  entities.push_back(*input_entity);
}

void LocationsEntitiesSystem::put_magwehr(Magwehr* input_entity) {
  MagwehrsSystem::put_magwehr(input_entity);
  entities.push_back(*input_entity);
}
void LocationsEntitiesSystem::put_player(Sentient* input_entity) {
  SentientsSystem::put_player(input_entity);
  entities.push_back(*input_entity);
}
void LocationsEntitiesSystem::put_sentient(Sentient* input_entity) {
  SentientsSystem::put_sentient(input_entity);
  entities.push_back(*input_entity);
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