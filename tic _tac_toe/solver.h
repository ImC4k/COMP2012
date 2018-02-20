#ifndef SOLVER_H_
#define SOLVER_H_

#include "utils.h"
#include "ttt.h"

class solver{ // this is the opponent object, will try to win tic tac toe game by predicting moves
  void placeMove(ttt board);
};

#endif

/*
  idea: for solver obj, if opponent will win soon, place there first.
  Else if solver obj is going to win in the next move, place there.
  Otherwise, find a spot where solver obj can created the most lines.

  Note: enum created has to add one more for temp input for solver obj
*/
