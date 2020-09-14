//
// Created by vydra on 9/14/20.
//

#pragma once

#include <entities/location_entities/data/GraficRenderData.hpp>
#include <entities/location_entities/data/PseudoRenderData.hpp>
#include <string>

class SentientParametersData {
 private:
  unsigned x;
  unsigned y;
  unsigned hp;
  unsigned mp;
  unsigned ap;
  unsigned wallet;
  unsigned pocket_size;
  std::string name;
  std::string nickname;
  PseudoRenderData *pseudo_data = nullptr;
  GraficRenderData *grafic_data = nullptr;

 public:
  explicit SentientParametersData(unsigned input_x, unsigned input_y, unsigned input_hp, unsigned input_mp,
                                  unsigned input_ap, unsigned input_wallet, unsigned input_pocket_size,
                                  std::string input_name, std::string input_nickname,
                                  PseudoRenderData *input_pseudo_data, GraficRenderData *input_grafic_data);
  ~SentientParametersData();

  unsigned int get_x() const;
  unsigned int get_y() const;
  unsigned int get_hp() const;
  unsigned int get_mp() const;
  unsigned int get_ap() const;
  unsigned int get_wallet() const;
  unsigned int get_pocket_size() const;
  std::string get_name() const;
  std::string get_nickname() const;
  PseudoRenderData *get_pseudo_data() const;
  GraficRenderData *get_grafic_data() const;

  void set_x(unsigned int input_x);
  void set_y(unsigned int input_y);
  void set_hp(unsigned int input_hp);
  void set_mp(unsigned int input_mp);
  void set_ap(unsigned int input_ap);
  void set_wallet(unsigned int input_wallet);
  void set_pocket_size(unsigned int input_pocket_size);
  void set_name(std::string input_name);
  void set_nickname(std::string input_nickname);
  void set_pseudo_data(PseudoRenderData *input_pseudo_data);
  void set_grafic_data(GraficRenderData *input_grafic_data);
};