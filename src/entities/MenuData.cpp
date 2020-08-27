//
// Created by vydra on 8/27/20.
//

#include "entities/MenuData.hpp"

#include <utility>

MenuData::MenuData(std::string *input_title, unsigned int input_count_choices, std::string **input_choices) {
  title = input_title;
  count_choices = input_count_choices;
  choices = input_choices;
  highlighted = 1;
}

MenuData::~MenuData() {
  delete title;
  for (unsigned i = 0; i < count_choices; i++) {
    delete choices[i];
  }
  delete choices;
}

std::string *MenuData::get_title() const {
  return title;
}

unsigned int MenuData::get_count_choices() const {
  return count_choices;
}

std::string *MenuData::get_choice(unsigned input_index) const {
  return choices[input_index];
}

std::string **MenuData::get_choices() const {
  return choices;
}

unsigned int MenuData::get_highlighted() const {
  return highlighted;
}

void MenuData::set_title(std::string *input_title) {
  title = input_title;
}

void MenuData::set_count_choices(unsigned int input_count_choices) {
  count_choices = input_count_choices;
}

void MenuData::set_choice(unsigned int input_index, std::string *input_choice) {
  choices[input_index] = input_choice;
}

void MenuData::set_choices(std::string **input_choices) {
  for (unsigned i = 0; i < count_choices; i++) {
    delete[] choices;
  }
  delete[] choices;
  choices = input_choices;
}

void MenuData::set_highlighted(unsigned int input_highlighted) {
  highlighted = input_highlighted;
}
