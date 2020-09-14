//
// Created by vydra on 8/27/20.
//

#include "systems/launcher_system/data/ParameterQueryData.hpp"

#include <string>
#include <vector>

ParameterQueryData::ParameterQueryData(std::string *input_title, std::vector<std::string *> *input_choices) {
  title = input_title;
  choices = input_choices;
  highlighted = 1;
}

ParameterQueryData::~ParameterQueryData() {
  delete title;
  choices->clear();
  delete choices;
}

std::string *ParameterQueryData::get_title() const {
  return title;
}

unsigned int ParameterQueryData::get_count_choices() const {
  return choices->size();
}

std::string *ParameterQueryData::get_choice(unsigned input_index) const {
  return choices->at(input_index);
}

std::vector<std::string *> *ParameterQueryData::get_choices() const {
  return choices;
}

unsigned int ParameterQueryData::get_highlighted() const {
  return highlighted;
}

void ParameterQueryData::set_title(std::string *input_title) {
  title = input_title;
}

void ParameterQueryData::set_choice(unsigned int input_index, std::string *input_choice) {
  delete choices->at(input_index);
  choices->at(input_index) = input_choice;
}

void ParameterQueryData::set_choices(std::vector<std::string *> *input_choices) {
  choices->clear();
  delete[] choices;
  choices = input_choices;
}

void ParameterQueryData::set_highlighted(unsigned int input_highlighted) {
  highlighted = input_highlighted;
}

std::vector<std::string *> *ParameterQueryData::create_choices(unsigned int input_count_choices,
                                                               const char **input_choices) {
  auto temp_choices = new std::vector<std::string *>();
  for (unsigned int i = 0; i < input_count_choices; i++) {
    temp_choices->push_back(new std::string(input_choices[i]));
  }
  return temp_choices;
}

std::vector<std::string *> *ParameterQueryData::create_choices(unsigned int input_count_choices,
                                                               std::string *input_choices) {
  auto temp_choices = new std::vector<std::string *>();
  for (unsigned int i = 0; i < input_count_choices; i++) {
    temp_choices->push_back(new std::string(input_choices[i]));
  }
  return temp_choices;
}
