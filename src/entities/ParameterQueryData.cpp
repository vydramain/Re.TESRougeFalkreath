//
// Created by vydra on 8/27/20.
//

#include "entities/ParameterQueryData.hpp"

#include <utility>

ParameterQueryData::ParameterQueryData(std::string *input_title, unsigned int input_count_choices, std::string **input_choices) {
  title = input_title;
  count_choices = input_count_choices;
  choices = input_choices;
  highlighted = 1;
}

ParameterQueryData::~ParameterQueryData() {
  delete title;
  for (unsigned i = 0; i < count_choices; i++) {
    delete choices[i];
  }
  delete choices;
}

std::string *ParameterQueryData::get_title() const {
  return title;
}

unsigned int ParameterQueryData::get_count_choices() const {
  return count_choices;
}

std::string *ParameterQueryData::get_choice(unsigned input_index) const {
  return choices[input_index];
}

std::string **ParameterQueryData::get_choices() const {
  return choices;
}

unsigned int ParameterQueryData::get_highlighted() const {
  return highlighted;
}

void ParameterQueryData::set_title(std::string *input_title) {
  title = input_title;
}

void ParameterQueryData::set_count_choices(unsigned int input_count_choices) {
  count_choices = input_count_choices;
}

void ParameterQueryData::set_choice(unsigned int input_index, std::string *input_choice) {
  choices[input_index] = input_choice;
}

void ParameterQueryData::set_choices(std::string **input_choices) {
  for (unsigned i = 0; i < count_choices; i++) {
    delete[] choices;
  }
  delete[] choices;
  choices = input_choices;
}

void ParameterQueryData::set_highlighted(unsigned int input_highlighted) {
  highlighted = input_highlighted;
}

std::string **ParameterQueryData::create_choices(unsigned int input_count_choices, const char **input_choices) {
  auto **temp_choices = new std::string*[input_count_choices];
  for(unsigned int i = 0; i < input_count_choices; i++ ) {
    temp_choices[i] = new std::string(input_choices[i]);
  }
  return temp_choices;
}
std::string **ParameterQueryData::create_choices(unsigned int input_count_choices, std::string *input_choices) {
  auto **temp_choices = new std::string*[input_count_choices];
  for(unsigned int i = 0; i < input_count_choices; i++ ) {
    temp_choices[i] = new std::string(input_choices[i]);
  }
  return temp_choices;
}
