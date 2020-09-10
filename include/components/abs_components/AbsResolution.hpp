//
// Created by vydra on 9/10/20.
//

#pragma once

class AbsResolution {
 protected:
  enum resolution {
    R_1920x1080,
    R_1280x720
  };

  resolution current_resolution = R_1280x720;
};