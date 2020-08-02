//
// Created by vydra on 15.07.2020.
//

#ifndef INCLUDE_ECS_ENTITIES_MAP_H_
#define INCLUDE_ECS_ENTITIES_MAP_H_

class Map {
 private:
  const unsigned size_x;
  const unsigned size_y;

  char **data;

 public:
  explicit Map(unsigned input_size_x = 0, unsigned input_size_y = 0, char **input_data = nullptr);
  ~Map();

  unsigned get_size_x() const;
  unsigned get_size_y() const;
  char get_cell(unsigned input_x, unsigned input_y) const;
};

#endif  // INCLUDE_ECS_ENTITIES_MAP_H_
