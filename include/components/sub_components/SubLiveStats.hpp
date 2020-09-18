//
// Created by vydra on 9/14/20.
//

#pragma once

#include "components/abs_components/AbsLiveStats.hpp"

class SubLiveStats : public AbsLiveStats {
 public:
  explicit SubLiveStats(unsigned input_hp, unsigned input_mp, unsigned input_ap);
  ~SubLiveStats();

  void take_damage(unsigned points);
  void use_up_magic(unsigned points);
  void act();

  void set_hp(unsigned input_points);
  void set_mp(unsigned input_points);
  void set_ap(unsigned input_points);
  void set_status(status input_status);

  unsigned get_hp() const;
  unsigned get_mp() const;
  unsigned get_ap() const;
  status get_status() const;
};