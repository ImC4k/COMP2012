/*
 * DrawTwoCard.h
 *
 *  Created on: Feb 5, 2018
 *      Author: kevinw
 */

#ifndef DRAWTWOCARD_H_
#define DRAWTWOCARD_H_
#include "SkipCard.h"

class DrawTwoCard: public SkipCard{
public:
  DrawTwoCard(Color color);
  virtual bool operator^(const Card& t) const;
  virtual void castEffect(Player*& currentPlayer, CardPile& drawPile, CardPile& discardPile); // next player draws addtional two cards
  ~DrawTwoCard();
protected:
  virtual void serialize(ostream& os) const;
  
};

#endif /* DRAWTWOCARD_H_ */

// print color<<"+"
