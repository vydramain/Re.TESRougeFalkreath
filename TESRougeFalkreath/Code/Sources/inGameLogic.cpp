#include "inGameLogic.h"

inGameLogic::inGameLogic() {
  RENDER_ = new renderGame();
  LOGICA_ = new logicComponents();

  INPUT_ = new inputKey();
  LOADFILE_ = new loadFile();
  MAP_ = new playMap();
}
inGameLogic::inGameLogic(unsigned renderMode) {
  RENDER_ = new renderGame(renderMode);
  LOGICA_ = new logicComponents();

  INPUT_ = new inputKey();
  LOADFILE_ = new loadFile();
  MAP_ = new playMap();
}
inGameLogic::~inGameLogic() {
  delete RENDER_;
  delete LOGICA_;

  delete INPUT_;
  delete LOADFILE_;
  delete MAP_;
}

unsigned inGameLogic::mainMenu() {
  bool isGO = true;
  unsigned nonshoise(0);
  do{
    RENDER_->mainMenu(nonshoise);
    terminal_refresh();
    INPUT_->Update();
    if (INPUT_->IsUp() && nonshoise > 1) {
      nonshoise--;
    } else{
      if (INPUT_->IsDown() && nonshoise < 4) {
        nonshoise++;
      }}

    if (INPUT_->IsExit()) {
      nonshoise = 0;
      isGO = 0;
    } else {
      if (INPUT_->IsEnter() && nonshoise != 0) {
        isGO = 0;
      }
    }
  } while(isGO);
  return nonshoise;
}