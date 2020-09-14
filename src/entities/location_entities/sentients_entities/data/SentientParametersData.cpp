//
// Created by vydra on 9/14/20.
//

#include "entities/location_entities/sentients_entities/data/SentientParametersData.hpp"

#include <string>
#include <utility>

SentientParametersData::SentientParametersData(unsigned input_x, unsigned input_y, unsigned input_hp, unsigned input_mp,
                                               unsigned input_ap, unsigned input_wallet, unsigned input_pocket_size,
                                               std::string input_name, std::string input_nickname,
                                               PseudoRenderData *input_pseudo_data,
                                               GraficRenderData *input_grafic_data) {
  x = input_x;
  y = input_y;
  hp = input_hp;
  mp = input_mp;
  ap = input_ap;
  wallet = input_wallet;
  pocket_size = input_pocket_size;
  name = std::move(input_name);
  nickname = std::move(input_nickname);
  pseudo_data = input_pseudo_data;
  grafic_data = input_grafic_data;
}

SentientParametersData::~SentientParametersData() {}

std::string SentientParametersData::get_name() const {
  return name;
}

void SentientParametersData::set_name(std::string input_name) {
  SentientParametersData::name = input_name;
}

std::string SentientParametersData::get_nickname() const {
  return nickname;
}

void SentientParametersData::set_nickname(std::string input_nickname) {
  SentientParametersData::nickname = input_nickname;
}

PseudoRenderData *SentientParametersData::get_pseudo_data() const {
  return pseudo_data;
}

void SentientParametersData::set_pseudo_data(PseudoRenderData *input_pseudo_data) {
  pseudo_data = input_pseudo_data;
}

GraficRenderData *SentientParametersData::get_grafic_data() const {
  return grafic_data;
}

void SentientParametersData::set_grafic_data(GraficRenderData *input_grafic_data) {
  grafic_data = input_grafic_data;
}

unsigned int SentientParametersData::get_x() const {
  return x;
}

void SentientParametersData::set_x(unsigned int input_x) {
  SentientParametersData::x = input_x;
}

unsigned int SentientParametersData::get_y() const {
  return y;
}

void SentientParametersData::set_y(unsigned int input_y) {
  SentientParametersData::y = input_y;
}

unsigned int SentientParametersData::get_pocket_size() const {
  return pocket_size;
}

void SentientParametersData::set_pocket_size(unsigned int input_pocket_size) {
  pocket_size = input_pocket_size;
}

unsigned int SentientParametersData::get_wallet() const {
  return wallet;
}

void SentientParametersData::set_wallet(unsigned int input_wallet) {
  SentientParametersData::wallet = input_wallet;
}

unsigned int SentientParametersData::get_hp() const {
  return hp;
}

unsigned int SentientParametersData::get_mp() const {
  return mp;
}

unsigned int SentientParametersData::get_ap() const {
  return ap;
}

void SentientParametersData::set_hp(unsigned int input_hp) {
  hp = input_hp;
}

void SentientParametersData::set_mp(unsigned int input_mp) {
  mp = input_mp;
}

void SentientParametersData::set_ap(unsigned int input_ap) {
  ap = input_ap;
}
