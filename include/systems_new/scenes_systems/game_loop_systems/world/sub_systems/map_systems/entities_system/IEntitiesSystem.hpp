//
// Created by vydra on 9/2/20.
//

#pragma once

#include "entities/location_entities/LocationsEntity.h"
#include "entities/location_entities/ambient_entities/Ambient.h"
#include "entities/location_entities/items_entities/Item.h"
#include "entities/location_entities/magwehrs_entities/Magwehr.h"
#include "entities/location_entities/sentients_entities/Sentient.h"

class IEntitiesSystem {
 public:
  virtual ~IEntitiesSystem() = default;

  virtual void put_ambient(Ambient *input_ambient) = 0;
  virtual void put_item(Item *input_entity) = 0;
  virtual void put_magwehr(Magwehr *input_entity) = 0;
  virtual void put_player(Sentient *input_entity) = 0;
  virtual void put_sentient(Sentient *input_entity) = 0;

  virtual Ambient *remove_ambient(unsigned input_index) = 0;
  virtual Item *remove_item(unsigned input_index) = 0;
  virtual Magwehr *remove_magwehr(unsigned input_index) = 0;
  virtual Sentient *remove_player() = 0;
  virtual Sentient *remove_sentient(unsigned input_index) = 0;

  virtual LocationsEntity *get_entity(unsigned input_index) = 0;
  virtual const LocationsEntity *get_entity(unsigned input_index) const = 0;
};
