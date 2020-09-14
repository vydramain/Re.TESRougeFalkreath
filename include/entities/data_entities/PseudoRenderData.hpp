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

  void set_pseudo_tile(const char *input_tile);
  void set_pseudo_color(unsigned input_color);

  const char* get_pseudo_tile() const;
  unsigned get_pseudo_color() const;
};
