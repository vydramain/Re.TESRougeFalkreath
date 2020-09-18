//
// Created by vydra on 8/27/20.
//

#pragma once

#include <string>
#include <vector>

#include "entities/scenes_entities/SceneType.hpp"

class ParameterQueryData {
 private:
  std::string *name;
  std::string *title;
  std::vector<std::string *> *choices;
  unsigned highlighted;

 public:
  explicit ParameterQueryData(std::string* input_name, std::string *input_title, std::vector<std::string *> *input_choices);
  ~ParameterQueryData();

  std::string* get_name() const;
  std::string *get_title() const;
  unsigned int get_count_choices() const;
  std::string *get_choice(unsigned input_index) const;
  std::vector<std::string *> *get_choices() const;
  unsigned int get_highlighted() const;

  void set_title(std::string *input_title);
  void set_choice(unsigned int input_index, std::string *input_choice);
  void set_choices(std::vector<std::string *> *input_choices);
  void set_highlighted(unsigned int input_highlighted);

  static std::vector<std::string *> *create_choices(unsigned int input_count_choices, const char **input_choices);
  static std::vector<std::string *> *create_choices(unsigned int input_count_choices, std::string *input_choices);
};
