//
// Created by vydra on 15.07.2020.
//

#include "ecs/entities/Map.h"

Map::Map(const unsigned input_size_x, const unsigned input_size_y, char **input_data)
    : size_x(input_size_x), size_y(input_size_y) {
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

Map::~Map() {
  for (unsigned i = 0; i < size_x; i++) {
    delete data[i];
  }
  delete data;
}

unsigned Map::get_size_x() const {
  return size_x;
}

unsigned Map::get_size_y() const {
  return size_y;
}

char Map::get_cell(unsigned input_x, unsigned input_y) const {
  return data[input_x][input_y];
}
