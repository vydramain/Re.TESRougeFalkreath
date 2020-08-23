//
// Created by vydra on 8/21/20.
//

#pragma once

class ILocationReader {
 public:
  virtual ~ILocationReader() = default;

  virtual const char* get_file_name() = 0;

  virtual bool open() = 0;
  virtual unsigned int get_x_location_size() = 0;
  virtual unsigned int get_y_location_size() = 0;

  virtual bool has_next() = 0;
  virtual unsigned int get_char() = 0;
};
