#ifndef TTT_H_
#define TTT_H_

#include "utils.h"
// enum ELEMENT {BLANK, P1, P2} this is just for self note, don't uncomment

class ttt{ // the playing board, stores the game information in inputs[]
  ELEMENT inputs[9];
public:
  ttt();
  // ~ttt();
  bool isVacant(const int& position) const; // returns true when a position is BLANK
  bool putElement(ELEMENT element, const int& position);
  void removeElement(int position); // for SOLVER class' recursion?
  void print() const; // print the current board;
  int findWin(const int& position); // returns number of lines created after putting  a synbol in board
  bool isGameOver();
};

#endif

// position ranges from 0...9
