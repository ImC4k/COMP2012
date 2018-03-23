/*
 * ReverseCard.h
 *
 *  Created on: Feb 2, 2018
 *      Author: kevinw
 */

#ifndef REVERSECARD_H_
#define REVERSECARD_H_
#include "Card.h"
#include "typeinfo"

class ReverseCard: public Card{
public:
  ReverseCard(Color color);
  virtual bool operator^(const Card& t) const;
  virtual void castEffect(Player*& currentPlayer, CardPile& drawPile, CardPile& discardPile);
  ~ReverseCard();
protected:
  virtual void serialize(ostream& os) const;
};

#endif /* REVERSECARD_H_ */
