//
// Created by vydra on 7/21/19.
//

#ifndef TESROUGEFALKREATH_CODE_HEADERS_LOGICPARTS_HUD_H_
#define TESROUGEFALKREATH_CODE_HEADERS_LOGICPARTS_HUD_H_

#include <BearLibTerminal.h>
#include "./player.h"

class hud {
 private:
 public:
  explicit hud(player GG);
  bool dialog;
  bool askDoorMark;
  bool askDoor();

  bool askArmorMark;
  bool askArmor();

  ///////////////////////////////// рендер
  void renderHud();
};

#endif  // TESROUGEFALKREATH_CODE_HEADERS_LOGICPARTS_HUD_H_
