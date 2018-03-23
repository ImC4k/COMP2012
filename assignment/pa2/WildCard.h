/*
 * WildCard.h
 *
 *  Created on: Feb 6, 2018
 *      Author: kevinw
 */

#ifndef WILDCARD_H_
#define WILDCARD_H_
#include "Card.h"
#include "Player.h"

class WildCard: public Card{
public:
  WildCard();
  WildCard(int point);
  virtual bool operator^(const Card& t) const;
  virtual void castEffect(Player*& currentPlayer, CardPile& drawPile, CardPile& discardPile);
  virtual void init();
  ~WildCard();
protected:
  virtual void serialize(ostream& os) const;

};

#endif /* WILDCARD_H_ */
