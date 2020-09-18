//
// Created by vydra on 8/21/20.
//

#include "systems/scenes_systems/statistics_systems/writer/StdStatisticsWriter.hpp"

StdStatisticsWriter::StdStatisticsWriter(const char *input_file_name) {
  PseudoLogSystem::log("StdStatisticsWriter", "Try to open", input_file_name);
  file_name = input_file_name;
  current_file = fopen(input_file_name, "a+");
  if (current_file == nullptr) {
    PseudoLogSystem::log("StdStatisticsWriter", "Can not open", input_file_name);
  }
}

StdStatisticsWriter::~StdStatisticsWriter() {
  if (current_file != nullptr) {
    fclose(current_file);
  }
}

void StdStatisticsWriter::set_cursor(Sentient *input_sentient) {
  unsigned temp_steps;
  do {
    int temp_i = 0;
    int current_character = 0;
    char *temp_str = new char[char_in_string]{};
    for (int l = 0; temp_str[l]; l++) {
      temp_str[l] = ' ';
    }
    while (current_character != '\n' && current_character != -1) {
      current_character = fgetc(current_file);
      temp_str[temp_i] = current_character;
      temp_i++;
    }

    if (current_character == -1) {
      return;
    }

    int i = 0;
    temp_steps = 0;
    int temp_spaces = 0;
    int temp_str_length = 0;

    while (temp_str[temp_str_length]) {
      temp_str_length++;
    }

    while (temp_spaces < 5) {
      if (temp_str[i] == ' ') {
        temp_spaces++;
      }
      i++;
    }

    int digit = temp_str_length - i - 2;
    while (digit >= 0) {
      temp_steps += std::pow(10, digit) * CCMech::char_to_int(temp_str[i]);
      digit--;
      i++;
    }

    delete[] temp_str;
  } while (temp_steps < input_sentient->get_steps_count());
}

void StdStatisticsWriter::free_file() {
  if (current_file != nullptr) {
    fclose(current_file);
  }
  current_file = fopen(file_name, "w+");
}

void StdStatisticsWriter::add_sentient_score(Sentient *input_sentient) {
  if (input_sentient != nullptr && current_file != nullptr) {
    fseek(current_file, 0, SEEK_SET);
//    char temp;
//    if (fread(&temp, 1, 1, current_file)) {
//      fseek(current_file, 0, SEEK_SET);
//      set_cursor(input_sentient);
//    }
    fprintf(current_file, "%s", input_sentient->get_nickname()->data());
    fprintf(current_file, " - Монет: ");
    char wallet[7];
    snprintf(wallet, (size_t) "%u", "%u", input_sentient->get_wallet());
    fprintf(current_file, "%s Шагов: ", wallet);
    char steps[11];
    snprintf(steps, (size_t) "%u", "%u", input_sentient->get_steps_count());
    fprintf(current_file, "%s\n", steps);
  }
}
