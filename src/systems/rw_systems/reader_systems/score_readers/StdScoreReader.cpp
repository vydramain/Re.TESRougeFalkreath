//
// Created by vydra on 8/21/20.
//

#include "systems/rw_systems/reader_systems/score_readers/StdScoreReader.hpp"

StdScoreReader::StdScoreReader(const char* input_file_name) {
  PseudoLogSystem::log("StdScoreReader", "Try to open", input_file_name);
  if (input_file_name != nullptr) {
    current_file = fopen(input_file_name, "r");
    if (current_file != nullptr) {
      strings_count = get_strings_count();
      return;
    }
  }
  PseudoLogSystem::log("StdScoreReader", "Can not open", input_file_name);
}

StdScoreReader::~StdScoreReader() {
  if (current_file != nullptr) {
    fclose(current_file);
  }
}

unsigned StdScoreReader::get_strings_count() {
  unsigned count = 0;
  fseek(current_file, 0, SEEK_SET);
  do {
    int temp = fgetc(current_file);
    if (temp == '\n') {
      count++;
    }
  } while (!feof(current_file));
  return count;
}

const char* StdScoreReader::get_string(unsigned int input_index) {
  if (current_file && input_index < strings_count) {
    fseek(current_file, 0, SEEK_SET);
    unsigned counter = 0;
    while (counter != input_index && !feof(current_file)) {
      int temp = fgetc(current_file);
      if (temp == '\n') {
        counter++;
      }
    }

    if (feof(current_file)) {
      return nullptr;
    }

    int i = 0;
    int current_character = 0;
    char* returning_string = new char[char_in_string];
    while (current_character != '\n' && !feof(current_file)) {
      current_character = fgetc(current_file);
      returning_string[i] = current_character;
      i++;
    }
    if (i != char_in_string) {
      for (int j = i; j < char_in_string; j++) {
        returning_string[i] = ' ';
      }
    }
    return returning_string;
  }
  return nullptr;
}