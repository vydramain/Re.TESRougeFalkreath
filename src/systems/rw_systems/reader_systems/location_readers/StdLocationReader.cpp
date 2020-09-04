//
// Created by vydra on 8/23/20.
//

#include "systems/rw_systems/reader_systems/location_readers/StdLocationReader.hpp"

StdLocationReader::StdLocationReader(const char* input_file_name) {
  file_name = input_file_name;
}

StdLocationReader::~StdLocationReader() {
  if (file != nullptr) {
    fclose(file);
  }
}

const char* StdLocationReader::get_file_name() {
  return file_name;
}

bool StdLocationReader::open() {
  file = fopen(file_name, "r");
  if (file != nullptr) {
    if (!feof(file)) {
      if (fscanf(file, "%u %u", &x_location_size, &y_location_size) == 0) {
        x_location_size = 0;
        y_location_size = 0;
        file = nullptr;
        return false;
      }
      getc(file);
      return true;
    }
  }
  return false;
}

unsigned int StdLocationReader::get_x_location_size() {
  return x_location_size;
}

unsigned int StdLocationReader::get_y_location_size() {
  return y_location_size;
}

bool StdLocationReader::has_next() {
  return feof(file);
}

unsigned int StdLocationReader::get_char() {
  return getc(file);
}
