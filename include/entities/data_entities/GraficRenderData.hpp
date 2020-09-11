//
// Created by vydra on 9/11/20.
//

#pragma once

class GraficRenderData {
 private:
  unsigned tile_number;

 public:
  explicit GraficRenderData(unsigned input_tile_number);
  ~GraficRenderData();

  void set_tile_number(unsigned input_tile_number);

  unsigned get_tile_number() const;

};