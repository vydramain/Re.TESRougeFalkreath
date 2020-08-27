//
// Created by vydra on 8/27/20.
//

#pragma once

#include <string>

#include "entities/scenes_entities/SceneType.hpp"

class ParameterQueryData {
 private:
  std::string *title;
  unsigned count_choices;
  std::string **choices;
  unsigned highlighted;

 public:
  explicit ParameterQueryData(std::string *input_title, unsigned input_count_choices, std::string **input_choices);
  ~ParameterQueryData();

  std::string *get_title() const;
  unsigned int get_count_choices() const;
  std::string *get_choice(unsigned input_index) const;
  std::string **get_choices() const;
  unsigned int get_highlighted() const;

  void set_title(std::string *input_title);
  void set_count_choices(unsigned int input_count_choices);
  void set_choice(unsigned int input_index, std::string *input_choice);
  void set_choices(std::string **input_choices);
  void set_highlighted(unsigned int input_highlighted);
};
