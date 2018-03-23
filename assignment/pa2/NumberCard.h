/*
 * NumberCard.h
 *
 *  Created on: Jan 29, 2018
 *      Author: kevinw
 */

#ifndef NUMBERCARD_H_
#define NUMBERCARD_H_
#include "Card.h"

class NumberCard : public Card{
  int number;
public:
  NumberCard(int number, Color color);
  virtual bool operator^(const Card&t) const;
  virtual void castEffect(Player*& currentPlayer, CardPile& drawPile, CardPile& discardPile);
  ~NumberCard();
protected:
  virtual void serialize(ostream& os) const;
};

#endif /* NUMBERCARD_H_ */
