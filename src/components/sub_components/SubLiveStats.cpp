//
// Created by vydra on 9/14/20.
//

#include "components/sub_components/SubLiveStats.hpp"

SubLiveStats::SubLiveStats(unsigned int input_hp, unsigned int input_mp, unsigned int input_ap) : AbsLiveStats() {
  hp = input_hp;
  mp = input_mp;
  ap = input_ap;
  current_status = NORMAL;
}

SubLiveStats::~SubLiveStats() = default;

void SubLiveStats::take_damage(unsigned int points) {
  if (points >= hp) {
    hp = 0;
    current_status = DEATH;
    return;
  }
  if (current_status == AT_DEATH || current_status == TIRED) {
    hp -= points * 2;
  } else {
    hp -= points;
  }
  if (hp < 30) {
    current_status = AT_DEATH;
  }
}

void SubLiveStats::use_up_magic(unsigned int points) {
  if (points > mp) {
    mp = 0;
    current_status = DEATH;
    return;
  }
  if (current_status == AT_DEATH || current_status == TIRED) {
    mp -= points * 2;
  } else {
    mp -= points;
  }
  if (mp < 30) {
    current_status = TIRED;
  }
}

void SubLiveStats::act() {
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

unsigned SubLiveStats::get_hp() const {
  return hp;
}

unsigned SubLiveStats::get_mp() const {
  return mp;
}

unsigned SubLiveStats::get_ap() const {
  return ap;
}

AbsLiveStats::status SubLiveStats::get_status() const {
  return current_status;
}

void SubLiveStats::set_hp(unsigned int input_points) {
  hp = input_points;
}

void SubLiveStats::set_mp(unsigned int input_points) {
  mp = input_points;
}

void SubLiveStats::set_ap(unsigned int input_points) {
  ap = input_points;
}

void SubLiveStats::set_status(AbsLiveStats::status input_status) {
  current_status = input_status;
}
