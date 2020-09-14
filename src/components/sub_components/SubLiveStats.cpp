//
// Created by vydra on 9/14/20.
//

#include "components/sub_components/SubLiveStats.hpp"

SubLiveSubStats::SubLiveSubStats(unsigned int input_hp, unsigned int input_mp, unsigned int input_ap) : AbsLiveStats() {
  hp = input_hp;
  mp = input_mp;
  ap = input_ap;
  current_status = NORMAL;
}

SubLiveSubStats::~SubLiveSubStats() = default;

void SubLiveSubStats::take_damage(unsigned int points) {
  if (points > hp) {
    hp = 0;
    current_status = DEATH;
    return;
  }
  if (current_status == AT_DEATH || current_status == TIRED) {
    hp - points * 2;
  } else {
    hp - points;
  }
  if (hp < 30) {
    current_status = AT_DEATH;
  }
}

void SubLiveSubStats::use_up_magic(unsigned int points) {
  if (points > mp) {
    mp = 0;
    current_status = DEATH;
    return;
  }
  if (current_status == AT_DEATH || current_status == TIRED) {
    mp - points * 2;
  } else {
    mp - points;
  }
  if (mp < 30) {
    current_status = TIRED;
  }
}

void SubLiveSubStats::act() {
  if (ap-- == 0) {
    current_status = DEATH;
    return;
  }
  if (ap < 30) {
    mp++;
    current_status = AT_DEATH;
    return;
  }
  mp += 2;
}

unsigned SubLiveSubStats::get_hp() const {
  return hp;
}
unsigned SubLiveSubStats::get_mp() const {
  return mp;
}
unsigned SubLiveSubStats::get_ap() const {
  return ap;
}
AbsLiveStats::status SubLiveSubStats::get_status() const {
  return current_status;
}
