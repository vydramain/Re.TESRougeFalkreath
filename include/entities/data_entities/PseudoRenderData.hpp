//
// Created by vydra on 9/11/20.
//

#pragma once

class PseudoRenderData {
 private:
  const char* tile;
  unsigned color;

 public:
  explicit PseudoRenderData(const char* input_tile, unsigned input_color);
  ~PseudoRenderData();

  void set_tile(const char *input_tile);
  void set_color(unsigned input_color);

  const char* get_tile() const;
  unsigned get_color() const;
};
