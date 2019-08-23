//
// Created by vydra on 8/21/19.
//

#ifndef TESROUGEFALKREATH_CODE_HEADERS_CONTROLCOMPONENTS_INPUTCOMMAND_H_
#define TESROUGEFALKREATH_CODE_HEADERS_CONTROLCOMPONENTS_INPUTCOMMAND_H_

struct inputCommand_ {
 private:
  unsigned move;
  unsigned act;

 public:
  inputCommand_() {
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
  unsigned moveOutCommand() {
    return move;
  }

  void actInCommand(unsigned Act) {
    act = Act;
  }
  unsigned actOutCommand() {
    return act;
  }
};

#endif  // TESROUGEFALKREATH_CODE_HEADERS_CONTROLCOMPONENTS_INPUTCOMMAND_H_
