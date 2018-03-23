/*
 * SkipCard.h
 *
 *  Created on: Feb 2, 2018
 *      Author: kevinw
 */

#ifndef SKIPCARD_H_
#define SKIPCARD_H_
#include "Card.h"
#include "typeinfo"

class SkipCard: public Card{
public:
  SkipCard(Color color);
  SkipCard(Color color, int point); // overloaded constructor for inheritance, point may not be same as SkipCard
  virtual bool operator^(const Card& t) const;
  virtual void castEffect(Player*& currentPlayer, CardPile& drawPile, CardPile& discardPile); // need to skip next player
  ~SkipCard();
protected:
  virtual void serialize(ostream& os) const;

};

#endif /* SKIPCARD_H_ */

// print Color<<"s";
