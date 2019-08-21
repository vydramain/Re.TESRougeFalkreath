//
// Created by vydra on 8/21/19.
//

#ifndef TESROUGEFALKREATH_INPUTCOMMAND_H
#define TESROUGEFALKREATH_INPUTCOMMAND_H

struct inputCommand_ {
 private:
  unsigned move;
  unsigned act;

 public:
  inputCommand_(){
    move = 0;
    act = 0;
  }
  void clearCommand() {
    move = 0;
    act = 0;
  }

  void moveInCommand(unsigned Move) {
    move = Move;
  }
  void moveOutCommand(unsigned& Move) {
    Move = move;
  }

  void actInCommand(unsigned Act) {
    act = Act;
  }
  void actOutCommand(unsigned& Act) {
    Act = act;
  }
};

#endif  // TESROUGEFALKREATH_INPUTCOMMAND_H
