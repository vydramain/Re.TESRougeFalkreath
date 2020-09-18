//
// Created by vydra on 9/17/20.
//

#pragma once

#include <string>

class LoadControlsEntitysData {
 private:
  std::string* name = nullptr;
  std::string* nickname = nullptr;
  unsigned x = 0;
  unsigned y = 0;

 public:
  explicit LoadControlsEntitysData();
  explicit LoadControlsEntitysData(std::string* input_name, std::string* input_nickname, unsigned input_x,
                                   unsigned input_y);
  ~LoadControlsEntitysData();

  void set_name(std::string* input_name);
  void set_nickname(std::string* input_nickname);
  void set_x(unsigned int input_x);
  void set_y(unsigned int input_y);

  std::string* get_name() const;
  std::string* get_nickname() const;
  unsigned int get_x() const;
  unsigned int get_y() const;

  void clear_fields();
};
