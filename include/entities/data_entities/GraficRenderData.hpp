//
// Created by vydra on 9/11/20.
//

#pragma once

class GraficRenderData {
 private:
  const char* tile_address;
  unsigned tile_number;

 public:
  explicit GraficRenderData(const char *input_tile_address, unsigned input_tile_number);
  ~GraficRenderData();

  void set_tile_address(const char *input_tile_address);
  void set_tile_number(unsigned input_tile_number);

  const char* get_tile_address() const;
  unsigned get_tile_number() const;

};