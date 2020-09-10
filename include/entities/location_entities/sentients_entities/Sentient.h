//
// Created by vydra on 8/3/20.
//

#pragma once

#include "components/sub_components/SubNickname.hpp"
#include "components/sub_components/SubPockets.hpp"
#include "components/sub_components/SubWalketh.hpp"
#include "entities/location_entities/LocationsEntity.h"

class Sentient : public SubNickname, public LocationsEntity, public SubWalketh, public SubPockets {
 public:
  explicit Sentient(const char *input_fio, const char *input_name, const char *input_tile, unsigned input_color,
                    unsigned input_current_x = 0, unsigned input_current_y = 0, unsigned input_pocket_size = 10,
                    unsigned input_wallet = 0);
  Sentient(const Sentient &input_sentient);
  Sentient(Sentient &&input_sentient) noexcept;
  Sentient &operator=(const Sentient &input_sentient);
  Sentient &operator=(Sentient &&input_sentient) noexcept;
  ~Sentient() override;

  bool operator==(const Sentient &rhs) const;
  bool operator!=(const Sentient &rhs) const;
};
