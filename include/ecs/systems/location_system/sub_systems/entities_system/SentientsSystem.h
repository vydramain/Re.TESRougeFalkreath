//
// Created by vydra on 8/3/20.
//

#pragma once

#include <vector>

#include "core/entities/location_enities/sentients_entities/Sentient.h"

class SentientsSystem {
 private:
  std::vector<Sentient*> sentients;

 public:
  explicit SentientsSystem();
  virtual ~SentientsSystem();

  virtual void put_player(Sentient *input_player);
  virtual Sentient *remove_player();

  Sentient *get_player();
  Sentient *get_sentient(unsigned input_index);

  unsigned get_sentients_size() const;
  int get_sentient_index(Sentient *input_magwehr);
  const Sentient *get_sentient(unsigned input_index) const;

 protected:
  virtual void put_sentient(Sentient *input_sentient);
  virtual Sentient *remove_sentient(unsigned input_index);
};
