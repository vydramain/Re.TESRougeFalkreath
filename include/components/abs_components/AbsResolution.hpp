//
// Created by vydra on 9/10/20.
//

#pragma once

class AbsResolution {
 public:
  enum resolution { R_1920x1080, R_1280x720 };

 protected:
  resolution current_resolution = R_1280x720;
};