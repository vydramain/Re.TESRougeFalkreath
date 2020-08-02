//
// Created by vydra on 12.07.2020.
//

#ifndef INCLUDE_ECS_SYSTEMS_RENDER_SYSTEM_INTERFACE_RENDER_H_
#define INCLUDE_ECS_SYSTEMS_RENDER_SYSTEM_INTERFACE_RENDER_H_

class interface_render {
 public:
  interface_render() = default;
  virtual ~interface_render() = default;

  virtual void clear_all() = 0;
  virtual void clear_area(unsigned in_x, unsigned in_y, unsigned out_x, unsigned out_y) = 0;
  virtual void render() = 0;
};

#endif  // INCLUDE_ECS_SYSTEMS_RENDER_SYSTEM_INTERFACE_RENDER_H_
