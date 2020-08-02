//
// Created by vydra on 8/3/20.
//

#ifndef INCLUDE_ECS_COMPONENTS_LOCATEABLE_H_
#define INCLUDE_ECS_COMPONENTS_LOCATEABLE_H_

class Locateable {
 private:
  unsigned current_x;
  unsigned current_y;

 public:
  explicit Locateable(unsigned input_x, unsigned input_y);
  ~Locateable();

  unsigned get_current_x() const;
  unsigned get_current_y() const;

  void set_current_x(unsigned int input_x);
  void set_current_y(unsigned int input_y);
};

#endif  // INCLUDE_ECS_COMPONENTS_LOCATEABLE_H_
