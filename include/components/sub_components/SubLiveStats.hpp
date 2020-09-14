//
// Created by vydra on 9/14/20.
//

#pragma once

#include "components/abs_components/AbsLiveStats.hpp"

class SubLiveSubStats : public AbsLiveStats {
 public:
  explicit SubLiveSubStats(unsigned input_hp, unsigned input_mp, unsigned input_ap);
  ~SubLiveSubStats();

  void take_damage(unsigned points);
  void use_up_magic(unsigned points);
  void act();

  unsigned get_hp() const;
  unsigned get_mp() const;
  unsigned get_ap() const;
  status get_status() const;
};