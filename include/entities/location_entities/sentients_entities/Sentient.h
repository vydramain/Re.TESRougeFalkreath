//
// Created by vydra on 8/3/20.
//

#pragma once

#include "components/sub_components/SubLiveStats.hpp"
#include "components/sub_components/SubNickname.hpp"
#include "components/sub_components/SubPockets.hpp"
#include "components/sub_components/SubSentientCondition.hpp"
#include "components/sub_components/SubWalketh.hpp"
#include "entities/location_entities/LocationsEntity.h"
#include "entities/location_entities/sentients_entities/data/SentientParametersData.hpp"

class Sentient : public SubNickname,
                 public LocationsEntity,
                 public SubLiveStats,
                 public SubWalketh,
                 public SubPockets,
                 public SubSentientCondition {
 public:
  explicit Sentient(SentientParametersData *input_data);
  Sentient(const Sentient &input_sentient);
  Sentient(Sentient &&input_sentient) noexcept;
  Sentient &operator=(const Sentient &input_sentient);
  Sentient &operator=(Sentient &&input_sentient) noexcept;
  ~Sentient() override;

  bool operator==(const Sentient &rhs) const;
  bool operator!=(const Sentient &rhs) const;
};
