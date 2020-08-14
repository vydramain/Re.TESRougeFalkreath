//
// Created by vydra on 15.07.2020.
//

#include "core/entities/location_enities/area_entities/Area.h"

Area::Area(const char *input_name, const unsigned input_size_x, const unsigned input_size_y, char **input_data)
    : LocationsEntity(input_name, ' ', 0x0000000), size_x(input_size_x), size_y(input_size_y) {
  if (input_data != nullptr) {
    data = new char *[size_x];
    for (unsigned i = 0; i < size_x; i++) {
      data[i] = new char[size_y];
    }
    for (unsigned i = 0; i < size_x; i++) {
      for (unsigned j = 0; j < size_y; j++) {
        data[i][j] = input_data[i][j];
      }
    }
  }
}

Area::Area(const Area &input_area)
    : LocationsEntity(input_area.get_name(), input_area.get_tile(), input_area.get_color()),
      size_x(input_area.get_size_x()),
      size_y(input_area.get_size_y()) {
  data = new char *[size_x];
  for (unsigned i = 0; i < size_x; i++) {
    data[i] = new char[size_y];
  }
  for (unsigned i = 0; i < size_x; i++) {
    for (unsigned j = 0; j < size_y; j++) {
      data[i][j] = input_area.get_cell(i, j);
    }
  }
}

Area::~Area() {
  for (unsigned i = 0; i < size_x; i++) {
    delete[] data[i];
  }
  delete[] data;
}

unsigned Area::get_size_x() const {
  return size_x;
}

unsigned Area::get_size_y() const {
  return size_y;
}
char Area::get_cell(unsigned input_x, unsigned input_y) const {
  return data[input_x][input_y];
}
